#include "QueueNode.hpp"

// Constructor y destructor
QueueNode::QueueNode(string data)
{
    this->data = data;
    this->next = nullptr;
}

QueueNode::~QueueNode()
{
    // Destructor vacio
}

// Getters
string QueueNode::getData() const
{
    return data;
}

QueueNode *QueueNode::getNext() const
{
    return next;
}

// Setters
void QueueNode::setData(string data)
{
    this->data = data;
}

void QueueNode::setNext(QueueNode *next)
{
    this->next = next;
}
