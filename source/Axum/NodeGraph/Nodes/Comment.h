
#ifndef _COMMENT_H
#define _COMMENT_H

#include "../Node.h"
#include <string>

namespace Axum {
namespace NodeGraph {

class Comment : public Node {
private:
  std::string commentText;

public:
  Comment(unsigned int _uid);

  std::string &getCommentText();

  void setCommentText(std::string &commentText);
};
} // namespace NodeGraph
} // namespace Axum
#endif //__COMMENT_H