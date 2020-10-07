/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _GRAPH_H
#define _GRAPH_H

#include "Link.h"
#include "Node.h"
#include "NodeGraphHelpers.h"
#include "ResourceTypes/Resource.h"
#include "Utils/Log/Log.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/unique_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <list>
#include <memory>
#include <vector>

namespace Axum {
namespace UI::Editor {
class MaterialEditor;
};

namespace NodeGraph {

class Graph : public ResourceType::Resource {
  friend class boost::serialization::access;

protected:
  std::vector<std::unique_ptr<Node>> mNodes;
  std::vector<Link> links;
  int lastNodeUID = INT_MIN;
  int lastLinkUID = INT_MIN;

public:
  int lastSocketUID = INT_MIN;
  Graph(){};

  /**
   * @brief Get the Node with uid = @a uid
   *
   * @param uid uid of the node to find
   * @return Node& reference to the node with uid = @a uid
   */
  Node &getNode(int uid);

  std::vector<std::unique_ptr<Node>> const &getNodes();

  std::vector<Link> const &getLinks();

  void addNode(Node *node);

  void deleteNode(int nodeUid);

  void addLink(Link link);

  void deleteLink(int linkId);

  void deleteLink(InputSocket *targetSocket);

  /**
   * @brief Transverses the node graph into a sequence.
   *
   * @return std::vector<Node *> the node graph transversed into sequence.
   */
  std::vector<Node *> transverse();

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &uid &mNodes &links &lastNodeUID &lastSocketUID &lastLinkUID;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &uid &mNodes &links &lastNodeUID &lastSocketUID &lastLinkUID;
    for (auto &link : links) {
      link.fromSocket->LinkTo(link.toSocket);
    }
    for (auto &nodePtr : mNodes) {
      nodePtr->parentGraph = this;
    }
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace NodeGraph
} // namespace Axum
BOOST_CLASS_VERSION(Axum::NodeGraph::Graph, 1)
#endif //_GRAPH_H
