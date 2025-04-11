#pragma once
#include <iostream>

#include "GameNode.hpp"

class GameQueue
{
private:
    GameNode *front;
    int size;

public:
    // Constructor y destructor
    GameQueue();
    ~GameQueue();

    // Métodos y funciones
    void enqueue(const GameElement &data);
    GameElement dequeue();
    void clear();
    int length();
    bool isEmpty();
};