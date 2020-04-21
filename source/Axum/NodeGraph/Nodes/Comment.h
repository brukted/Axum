
#ifndef _COMMENT_H
#define _COMMENT_H

#include "../Node.h"
#include <string>

class Comment:public Node 
{
private:
    std::string commentText;
    /* data */
public:
    Comment(/* args */);
    ~Comment();
    std::string& getCommentText() {
    	return this->commentText;
    }
    void setCommentText(std::string &commentText) {
    	this->commentText = commentText;
    }
};

#endif //__COMMENT_H