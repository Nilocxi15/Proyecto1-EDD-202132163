#include "BoxesDistance.hpp"

void BoxesDistance::printBoxes(GameQueue *queue, int posX, int posY, int posZ)
{
    int treasureX = posX;
    int treasureY = posY;
    int treasureZ = posZ;

    if (queue == nullptr || queue->length() == 0)
    {
        cout << "No encontro ninguna pista." << endl;
        return;
    }

    cout << "Pistas encontradas y su distancia al tesoro:" << endl;
    for (int i = 0; i < queue->length(); i++)
    {
        GameElement box = queue->dequeue();
        int boxDistance = abs(box.getPosX() - treasureX) + abs(box.getPosY() - treasureY) + abs(box.getPosZ() - treasureZ);
        cout << "La pista en la ubicacion (" << box.getPosX() << "," << box.getPosY() << "," << box.getPosZ();
        cout << ") se encontraba " << boxDistance << " casillas de distancia del tesoro" << endl;
    }
}