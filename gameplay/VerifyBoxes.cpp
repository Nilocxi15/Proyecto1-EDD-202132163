#include "VerifyBoxes.hpp"

VerifyBoxes::~VerifyBoxes()
{
    cout << "Destructor de VerifyBoxes" << endl;
    delete this->specialBoxes;
}

void VerifyBoxes::append(GameElement element)
{
    this->specialBoxes->push_back(element);    
}

GameElement VerifyBoxes::searchBox(int posX, int posY, int posZ) const
{
    cout << "Tamanio del puntero desde search: " << this->specialBoxes->size() << endl;
    cout << "Posicion de la casilla: " << posX << ", " << posY << ", " << posZ << endl;
    
    return GameElement("", 0, 0, 0, 0);
}