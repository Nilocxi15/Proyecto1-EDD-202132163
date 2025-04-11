#pragma once
#include <iostream>

#include "../queue/GameQueue.hpp"
#include "../models/GameElement.hpp"

using namespace std;

class BoxesDistance
{
private:
    GameQueue *queue;
    
public:
    void addBox(GameElement &box);
    void printBoxes();
};