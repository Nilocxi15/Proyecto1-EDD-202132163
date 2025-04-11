#include "GameQueue.hpp"

// Constructor y destructor
GameQueue::GameQueue()
{
    this->front = nullptr;
    size = 0;
}

GameQueue::~GameQueue()
{
    clear();
}

// Métodos y funciones
void GameQueue::enqueue(const GameElement &data)
{
    GameNode *newNode = new GameNode(data);
    if (front == nullptr)
    {
        front = newNode;
    }
    else
    {
        GameNode *temp = front;
        while (temp != nullptr)
        {
            if (temp->getNext() == nullptr)
            {
                temp->setNext(newNode);
                break;
            }
            temp = temp->getNext();
        }
    }
    size++;
}

GameElement GameQueue::dequeue()
{
    if (front == nullptr)
    {
        cout << "ERROR. " << endl;
        throw out_of_range("No hay registro del historial de partidas");
        return GameElement("", 0, 0, 0, 0);
    }
    else
    {
        GameNode *temp = front;
        front = front->getNext();
        GameElement data = temp->getData();
        delete temp;
        size--;
        return data;
    }
}

int GameQueue::length()
{
    return size;
}

void GameQueue::clear()
{
    while (front != nullptr)
    {
        GameNode *temp = front;
        front = front->getNext();
        delete temp;
    }
    size = 0;
}