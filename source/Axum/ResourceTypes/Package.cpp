/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Package.h"

/**
 * Package implementation
 *
 * Easily Serializable Data Type containing all infos about the current session
 */

namespace Axum {
namespace ResourceType {
NodeGraph::Logic::LogicGraph &
Package::AddLogicGraph(NodeGraph::Logic::LogicGraph graph, Folder *folder) {
  graph.uid = ++LastUID;
  LogicGraphs.push_back(std::move(graph));
  auto &graphRef = LogicGraphs.back();
  if (folder == nullptr)
    root.AddResource(&graphRef);
  else
    folder->AddResource(&graphRef);
  return graphRef;
}

ImageTexture &Package::AddImageTexture(ImageTexture texture, Folder *folder) {
  texture.uid = ++LastUID;
  ImageTextures.push_back(std::move(texture));
  auto &Ref = ImageTextures.back();
  if (folder == nullptr)
    root.AddResource(&Ref);
  else
    folder->AddResource(&Ref);
  return Ref;
}

VectorTexture &Package::AddVectorTexture(VectorTexture texture,
                                         Folder *folder) {
  texture.uid = ++LastUID;
  VectorTextures.push_back(std::move(texture));
  auto &Ref = VectorTextures.back();
  if (folder == nullptr)
    root.AddResource(&Ref);
  else
    folder->AddResource(&Ref);
  return Ref;
}

Scene &Package::AddScene(Scene scene, Folder *folder) {
  scene.uid = ++LastUID;
  Scenes.push_back(std::move(scene));
  auto &Ref = Scenes.back();
  if (folder == nullptr)
    root.AddResource(&Ref);
  else
    folder->AddResource(&Ref);
  return Ref;
}

Font &Package::AddFont(Font font, Folder *folder) {
  font.uid = ++LastUID;
  Fonts.push_back(std::move(font));
  auto &Ref = Fonts.back();
  if (folder == nullptr)
    root.AddResource(&Ref);
  else
    folder->AddResource(&Ref);
  return Ref;
}

Package &Package::AddPackage(Package pkg, Folder *folder) {
  pkg.uid = ++LastUID;
  Packages.push_back(std::move(pkg));
  auto &Ref = Packages.back();
  if (folder == nullptr)
    root.AddResource(&Ref);
  else
    folder->AddResource(&Ref);
  return Ref;
}

NodeGraph::Material::MaterialGraph &
Package::AddMaterialGraph(NodeGraph::Material::MaterialGraph graph,
                          Folder *folder) {
  graph.uid = ++LastUID;
  MaterialGraphs.push_back(std::move(graph));
  auto &graphRef = MaterialGraphs.back();
  if (folder == nullptr)
    root.AddResource(&graphRef);
  else
    folder->AddResource(&graphRef);
  return graphRef;
}

Folder &Package::GetRootFolder() { return root; }

Package::Package(unsigned int _uid, std::string name, bool isLinked,
                 std::string path) {
  this->type = Type::Package;
  uid = _uid;
  if (name == "")
    this->name.SetValue(_("Untitled Package"));
  else
    this->name.SetValue(name);
  this->isLinked = isLinked;
  this->Path = Path;
  root.name.SetValue("root");
  root.package = this;
}

Resource &Package::FindResource(unsigned int _uid) {
  for (auto &var : MaterialGraphs) {
    if (var.uid == _uid)
      return var;
  }
  for (auto &var : LogicGraphs) {
    if (var.uid == _uid)
      return var;
  }
  for (auto &var : Fonts) {
    if (var.uid == _uid)
      return var;
  }
  for (auto &var : ImageTextures) {
    if (var.uid == _uid)
      return var;
  }
  for (auto &var : Scenes) {
    if (var.uid == _uid)
      return var;
  }
  for (auto &var : VectorTextures) {
    if (var.uid == _uid)
      return var;
  }
  for (auto &var : Packages) {
    if (var.uid == _uid)
      return var;
  }
  AX_LOG_CORE_ERROR(
      "Package {0} is requested non-existent resource uid : {0:d}",
      name.GetValue(), _uid)
  throw std::runtime_error("Resource doesn't exist");
}

Folder *Package::RemoveResource(Resource &resource) {
  AX_CORE_ASSERT((resource.type) != ResourceType::Resource::Type::Folder);
  AX_CORE_ASSERT((resource.type) != ResourceType::Resource::Type::Generic);
  auto resUID = resource.uid;
  switch (resource.type) {
  case ResourceType::Resource::Type::Package: {
    Packages.remove_if(
        [resUID](ResourceType::Package &res) { return res.uid == resUID; });
    return nullptr;
  } break;
  case ResourceType::Resource::Type::Font: {
    Fonts.remove_if(
        [resUID](ResourceType::Font &res) { return res.uid == resUID; });
  } break;
  case ResourceType::Resource::Type::ImageTexture: {
    ImageTextures.remove_if([resUID](ResourceType::ImageTexture &res) {
      return res.uid == resUID;
    });
  } break;
  case ResourceType::Resource::Type::Scene: {
    Scenes.remove_if(
        [resUID](ResourceType::Scene &res) { return res.uid == resUID; });
  } break;
  case ResourceType::Resource::Type::VectorTexture: {
    VectorTextures.remove_if([resUID](ResourceType::VectorTexture &res) {
      return res.uid == resUID;
    });
  } break;
  case ResourceType::Resource::Type::MaterialGraph: {
    MaterialGraphs.remove_if([resUID](NodeGraph::Material::MaterialGraph &res) {
      return res.uid == resUID;
    });
  } break;
  case ResourceType::Resource::Type::LogicGraph: {
    LogicGraphs.remove_if([resUID](NodeGraph::Logic::LogicGraph &res) {
      return res.uid == resUID;
    });
  } break;
  }
  return root.RemoveResource(resUID);
}

Folder *Package::RemoveResource(unsigned int _uid) {
  Resource &resource = this->FindResource(_uid);
  return RemoveResource(resource);
}

} // namespace ResourceType
} // namespace Axum