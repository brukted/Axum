
#include "Comment.h"

Comment::Comment(unsigned int _uid)
{
    uid = _uid;
}

std::string &Comment::getCommentText()
{
    return (this->commentText);
}
void Comment::setCommentText(std::string &commentText)
{
    this->commentText = commentText;
}