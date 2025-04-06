#include "DoubleLinkedList.hpp"

// Constructor y destructor
DoubleLinkedList::DoubleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
    Node *current = this->head;
    while (current != nullptr)
    {
        Node *next = current->getNext();
        delete current;
        current = next;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// Getters
int DoubleLinkedList::length() const
{
    return this->size;
}

SparseMatrix *DoubleLinkedList::getNext(int iterator) const
{
    Node *current = this->head;

    for (int i = 0; i < iterator; i++)
    {
        current = current->getNext();
    }

    return current->getData();
}

SparseMatrix *DoubleLinkedList::getPrev(int iterator) const
{
    Node *current = this->tail;

    for (int i = 0; i < iterator - 1; i++)
    {
        current = current->getPrev();
    }

    return current->getData();
}

SparseMatrix *DoubleLinkedList::getFirst() const
{
    if (this->head != nullptr)
    {
        return this->head->getData();
    }
    else
    {
        throw runtime_error("ERROR. No hay elementos en la lista");
    }
}

// Métodos
void DoubleLinkedList::append(SparseMatrix *sparseMatrix)
{
    if (sparseMatrix == nullptr)
    {
        throw std::invalid_argument("No se puede agregar una matriz nula");
    }

    Node *newNode = new Node(sparseMatrix);

    if (this->head == nullptr && this->tail == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->setNext(newNode);
        newNode->setPrev(this->tail);
        this->tail = newNode;
    }
    this->size++;
}
