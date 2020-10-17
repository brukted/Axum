/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PACKAGE_H
#define _PACKAGE_H

#include "NodeGraph/LogicGraph.h"
#include "NodeGraph/MaterialGraph.h"
#include "ResourceTypes/Folder.h"
#include "ResourceTypes/Font.h"
#include "ResourceTypes/ImageTexture.h"
#include "ResourceTypes/Resource.h"
#include "ResourceTypes/Scene.h"
#include "ResourceTypes/VectorTexture.h"
#include "Utils/PathUtils/PathUtils.h"
#include "Utils/Translation/Translation.h"
#include <algorithm>
#include <assert.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/version.hpp>
#include <fstream>
#include <stdlib.h>
#include <vector>

namespace Axum {
namespace ResourceType {

class Package : public Resource {
  friend class boost::serialization::access;

private:
  std::list<NodeGraph::Material::MaterialGraph> MaterialGraphs;
  std::list<NodeGraph::Logic::LogicGraph> LogicGraphs;
  std::list<ResourceType::Font> Fonts;
  std::list<ResourceType::ImageTexture> ImageTextures;
  std::list<ResourceType::Scene> Scenes;
  std::list<ResourceType::VectorTexture> VectorTextures;
  std::list<ResourceType::Package> Packages;
  Axum::ResourceType::Folder RootFolder;
  unsigned int LastUID = 0;

public:
  /**
   * @brief Construct a new Package object
   *
   * @param name Name of the package.
   * @param type Type of the package embedded or linked. Embedded packages are
   * parent packages while linked packages are dependencies required by parent
   * packages.
   * @param Path Path of the package if linked type.
   */
  Package(unsigned int _uid = 0, std::string name = "", bool isLinked = false,
          std::string Path = "");

  /**
   * @brief Add material graph to the package.
   *
   * @param graph Graph to add.
   * @param folder Folder to add the resource to.
   * @return MaterialGraph& Reference to the graph in the package.
   */
  NodeGraph::Material::MaterialGraph &
  AddMaterialGraph(NodeGraph::Material::MaterialGraph graph,
                   Folder *folder = nullptr);

  /**
   * @brief Add logic graph to the package.
   *
   * @param graph Graph to add.
   * @param folder Folder to add the resource to.
   * @return LogicGraph& Reference to the graph in the package.
   */
  NodeGraph::Logic::LogicGraph &
  AddLogicGraph(NodeGraph::Logic::LogicGraph graph, Folder *folder = nullptr);

  /**
   * @brief Add image texture to the package.
   *
   * @param texture Image texture to add.
   * @param folder Folder to add the resource to.
   * @return ImageTexture& Reference to the texture in the package.
   */
  ImageTexture &AddImageTexture(ImageTexture texture, Folder *folder = nullptr);

  /**
   * @brief Add vector texture to the package.
   *
   * @param texture Vector texture to add.
   * @param folder Folder to add the resource to.
   * @return VectorTexture& Reference to the texture in the package.
   */
  VectorTexture &AddVectorTexture(VectorTexture texture,
                                  Folder *folder = nullptr);

  /**
   * @brief Add scene to the package.
   *
   * @param scene Scene to add.
   * @param folder Folder to add the resource to.
   * @return Scene& Reference to the scene in the package.
   */
  Scene &AddScene(Scene scene, Folder *folder = nullptr);

  /**
   * @brief Add font to the package.
   *
   * @param font Font to add.
   * @param folder Folder to add the resource to.
   * @return Font& Reference to the font in the package.
   */
  Font &AddFont(Font font, Folder *folder = nullptr);

  /**
   * @brief Add sub package to the package.
   *
   * @param pkg Package to add.
   * @param folder Folder to add the resource to.
   * @return Package& Reference to the sub package in the package.
   */
  Package &AddPackage(Package pkg, Folder *folder = nullptr);

  /**
   * @brief Find a resource with the specified uid.
   *
   * @param uid Unique identifier of the resource.
   * @return Resource& reference to the resource by uid.
   */
  Resource &FindResource(unsigned int uid);

  /**
   * @brief Remove the resource from the package and folder. This is slower
   * compared to FindResource(Resource& resource).
   *
   * @param uid UID of the resource to remove.
   * @return Folder* The folder that was containing the resource. nullptr if
   * the resource was not found.
   */
  Folder *RemoveResource(unsigned int uid);

  /**
   * @brief Remove the resource from the package and folder.
   *
   * @param resource Resource to remove.
   * @return Folder* The folder that was containing the resource. nullptr if
   * the resource was not found.
   */
  Folder *RemoveResource(Resource &resource);

  /**
   * @brief Get the Root Folder.
   *
   * @return Folder&
   */
  Folder &GetRootFolder();

  /**
   * @warning This is defined only to make std::list work.
   *
   */
  Package &operator=(const Package & /*pkg*/) {
    AX_LOG_CORE_CRITICAL("Copy operator for package called")
    assert(false);
  };
  Package(Package const & /*rhs*/) {
    AX_LOG_CORE_CRITICAL("Copy operator for package called")
    assert(false);
  };

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int /*version*/) const {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &LastUID;
    if (!isLinked)
      ar &MaterialGraphs &LogicGraphs &Fonts &ImageTextures &Scenes
          &VectorTextures &Packages &RootFolder;
  }

  template <class Archive>
  void load(Archive &ar, const unsigned int /*version*/) {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &LastUID;
    if (!isLinked) {
      ar &MaterialGraphs &LogicGraphs &Fonts &ImageTextures &Scenes
          &VectorTextures &Packages &RootFolder;
    } else {
      /// @brief formattedPath is a path with replaced internal dependency uri
      /// with proper path eg: AX://test.pkg ->
      /// $systemResourcesPath$/packages/test.pkg
      std::string formattedPath = Path;
      std::size_t i = formattedPath.find("AX://");
      if (i != formattedPath.npos)
        formattedPath.replace(i, 5, (Utils::PathUtils::systemResourcesPath + "/"));
      std::ifstream ifs(std::move(formattedPath));
      boost::archive::text_iarchive ia(ifs);
      ia >> *this;
      isLinked = true;
    }
    // Update package pointer for each resources and folders
    std::function<void(Folder &)> UpdatePkgForFolder = [&](Folder &folder) {
      folder.package = this;
      for (auto &subFolder : folder.GetSubFolders()) {
        UpdatePkgForFolder(subFolder);
      }
    };
    auto UpdatePackagePtr = [this](Resource &res) { res.package = this; };
    std::for_each(MaterialGraphs.begin(), MaterialGraphs.end(),
                  UpdatePackagePtr);
    std::for_each(LogicGraphs.begin(), LogicGraphs.end(), UpdatePackagePtr);
    std::for_each(ImageTextures.begin(), ImageTextures.end(), UpdatePackagePtr);
    std::for_each(Fonts.begin(), Fonts.end(), UpdatePackagePtr);
    std::for_each(Scenes.begin(), Scenes.end(), UpdatePackagePtr);
    std::for_each(VectorTextures.begin(), VectorTextures.end(),
                  UpdatePackagePtr);
    std::for_each(Packages.begin(), Packages.end(), UpdatePackagePtr);
    UpdatePkgForFolder(this->RootFolder);
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

} // namespace ResourceType
} // namespace Axum
BOOST_CLASS_VERSION(Axum::ResourceType::Package, 1)

#endif //_PACKAGE_H