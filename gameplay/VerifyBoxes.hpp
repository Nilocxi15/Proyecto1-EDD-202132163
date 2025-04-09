#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "../models/GameElement.hpp"

using namespace std;

class VerifyBoxes
{
private:
    vector<GameElement> *specialBoxes = new vector<GameElement>();

public:
    // Constructor
    VerifyBoxes();

    // Destructor
    ~VerifyBoxes();

    // Setter
    void append(GameElement element);
    GameElement searchBox(int posX, int posY, int posZ) const;
};