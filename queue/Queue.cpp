#include "Queue.hpp"

// Constructor y destructor
Queue::Queue()
{
    this->front = nullptr;
    size = 0;
}

Queue::~Queue()
{
    clear();
}

// Metodos y funciones
void Queue::enqueue(const string &data)
{
    QueueNode *newNode = new QueueNode(data);
    if (front == nullptr)
    {
        front = newNode;
    }
    else
    {
        QueueNode *temp = front;
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

string Queue::dequeue()
{
    if (front == nullptr)
    {
        cout << "ERROR. " << endl;
        throw out_of_range("No hay registro del historial de partidas");
        return "";
    }
    else
    {
        QueueNode *temp = front;
        front = front->getNext();
        string data = temp->getData();
        delete temp;
        size--;
        return data;
    }
}

int Queue::length()
{
    return size;
}

void Queue::clear()
{
    while (front != nullptr)
    {
        QueueNode *temp = front;
        front = front->getNext();
        delete temp;
    }
    size = 0;
}

void Queue::print()
{
    if (front == nullptr)
    {
        cout << "No hay registro del historial de partidas" << endl;
        return;
    }

    QueueNode *temp = front;
    while (temp != nullptr)
    {
        cout << temp->getData() << endl;
        temp = temp->getNext();
    }
}

bool Queue::isEmpty()
{
    return size == 0;
}