#pragma once

#include <string>

using namespace std;

class GameElement
{
private:
    string name;
    int posX;
    int posY;
    int posZ;
    int actionPoints;

public:
    // Constructor
    GameElement(string name, int posX, int posY, int posZ, int actionPoints);

    // Getters
    string getName() const;
    int getPosX() const;
    int getPosY() const;
    int getPosZ() const;
    int getActionPoints() const;
};