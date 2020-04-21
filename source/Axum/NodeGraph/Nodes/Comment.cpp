
#include "Comment.h"

Comment::Comment(/* args */)
{
}

Comment::~Comment()
{
}

std::string& Comment::getCommentText() {
    	return (this->commentText);
    }
void Comment::setCommentText(std::string &commentText) {
    this->commentText = commentText;
}