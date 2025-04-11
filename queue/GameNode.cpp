#include "GameNode.hpp"

// Constructor y destructor
GameNode::GameNode(GameElement data) : data(data)
{
    this->next = nullptr;
}

GameNode::~GameNode()
{
    // Destructor vacio
}

// Getters
GameElement GameNode::getData() const
{
    return data;
}

GameNode *GameNode::getNext() const
{
    return next;
}

// Setters
void GameNode::setData(GameElement data)
{
    this->data = data;
}

void GameNode::setNext(GameNode *next)
{
    this->next = next;
}