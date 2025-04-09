#include "GameElement.hpp"

// Constructor
GameElement::GameElement(string name, int posX, int posY, int posZ, int actionPoints)
{
    this->name = name;
    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;
    this->actionPoints = actionPoints;
}

// Getters
string GameElement::getName() const
{
    return this->name;
}

int GameElement::getPosX() const
{
    return this->posX;
}

int GameElement::getPosY() const
{
    return this->posY;
}

int GameElement::getPosZ() const
{
    return this->posZ;
}

int GameElement::getActionPoints() const
{
    return this->actionPoints;
}