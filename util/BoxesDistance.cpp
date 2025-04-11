#include "BoxesDistance.hpp"

void BoxesDistance::addBox(GameElement &box)
{
    if (queue == nullptr)
    {
        queue = new GameQueue();
    }
    queue->enqueue(box);
}

void BoxesDistance::printBoxes()
{
    if (queue == nullptr || queue->length() == 0)
    {
        cout << "No encontro ninguna pista." << endl;
        return;
    }

    cout << "Pistas encontradas y su distancia al tesoro:" << endl;
    for (int i = 0; i < queue->length(); i++)
    {
        GameElement box = queue->dequeue();
        cout << "Caja #" << i + 1 << ": " << box.getName() << endl;
    }
}