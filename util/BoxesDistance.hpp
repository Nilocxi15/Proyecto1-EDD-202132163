#pragma once
#include <iostream>

#include "../queue/GameQueue.hpp"
#include "../models/GameElement.hpp"

using namespace std;

class BoxesDistance
{
public:
    void printBoxes(GameQueue *queue, int posX, int posY, int posZ);
};