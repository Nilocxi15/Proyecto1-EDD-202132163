#include "Node.hpp"

// Constructor y destructor
Node::Node(SparseMatrix *matrix)
{
    this->matrix = matrix;
    this->next = nullptr;
    this->prev = nullptr;
}

Node::~Node()
{
}

// Getters
SparseMatrix *Node::getData() const
{
    return matrix;
}

Node *Node::getNext() const
{
    return next;
}

Node *Node::getPrev() const
{
    return prev;
}

// Setters
void Node::setData(SparseMatrix *matrix)
{
    this->matrix = matrix;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

void Node::setPrev(Node *prev)
{
    this->prev = prev;
}