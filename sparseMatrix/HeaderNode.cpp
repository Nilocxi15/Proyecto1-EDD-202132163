#include "HeaderNode.hpp"

// Constructor y destructor
HeaderNode::HeaderNode(int id)
{
    this->id = id;
    this->next = nullptr;
    this->prev = nullptr;
    this->access = nullptr;
}

HeaderNode::~HeaderNode()
{
    // Destructor
}

// Getters
int HeaderNode::getId() const
{
    return this->id;
}

HeaderNode *HeaderNode::getNext() const
{
    return this->next;
}

HeaderNode *HeaderNode::getPrev() const
{
    return this->prev;
}

CellNode *HeaderNode::getAccess() const
{
    return this->access;
}

// Setters
void HeaderNode::setId(const int id)
{
    this->id = id;
}

void HeaderNode::setNext(HeaderNode *next)
{
    this->next = next;
}

void HeaderNode::setPrev(HeaderNode *prev)
{
    this->prev = prev;
}

void HeaderNode::setAccess(CellNode *access)
{
    this->access = access;
}