#pragma once
#include <iostream>

#include "QueueNode.hpp"

class Queue
{
private:
    QueueNode *front;
    int size;

public:
    // Constructor y destructor
    Queue();
    ~Queue();

    // Métodos y funciones
    void enqueue(const string &data);
    string dequeue();
    void clear();
    void print();
    int length();
    bool isEmpty();
};
