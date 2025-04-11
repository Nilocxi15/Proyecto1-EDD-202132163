#pragma once

#include "../models/GameElement.hpp"

class GameNode
{
private:
    GameElement data;
    GameNode *next;    

public:
// Constructor y destructor
    GameNode(GameElement data);
    ~GameNode();

// Getters
    GameElement getData() const;
    GameNode *getNext() const;

// Setters
    void setData(GameElement data);
    void setNext(GameNode *next);
};