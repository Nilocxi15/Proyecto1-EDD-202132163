#include "HeadersList.hpp"

// Constructor y destructor
HeadersList::HeadersList(const string type)
{
    this->type = type;
    this->first = nullptr;
    this->last = nullptr;
    this->size = 0;
}

HeadersList::~HeadersList()
{
    HeaderNode *current = this->first;
    HeaderNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->getNext();
        delete current;
        current = next;
    }
}

// Getters
int HeadersList::length() const
{
    return this->size;
}

HeaderNode *HeadersList::get(int id) const
{
    HeaderNode *temp = this->first;
    while (temp != nullptr)
    {
        if (temp->getId() == id)
        {
            return temp;
        }
        temp = temp->getNext();
    }
    return nullptr;
}

// Setters
void HeadersList::setType(string type)
{
    this->type = type;
}

// Métodos
void HeadersList::add(HeaderNode *newNode)
{
    if (first == nullptr)
    {
        this->first = newNode;
        this->last = newNode;
    }
    else
    {
        if (newNode->getId() < first->getId())
        {
            newNode->setNext(first);
            first->setPrev(newNode);
            first = newNode;
        }
        else if (newNode->getId() > last->getId())
        {
            last->setNext(newNode);
            newNode->setPrev(last);
            last = newNode;
        }
        else
        {
            HeaderNode *temp = first;
            while (temp != nullptr)
            {
                if (newNode->getId() < temp->getId())
                {
                    newNode->setNext(temp);
                    newNode->setPrev(temp->getPrev());
                    temp->getPrev()->setNext(newNode);
                    temp->setPrev(newNode);
                    break;
                }
                else if (newNode->getId() > temp->getId())
                {
                    temp = temp->getNext();
                }
                else
                {
                    break;
                }
            }
        }
    }
    this->size++;
}

void HeadersList::print()
{
    HeaderNode *temp = this->first;
    while (temp != nullptr)
    {
        cout << temp->getId() << " ";
        temp = temp->getNext();
    }
}