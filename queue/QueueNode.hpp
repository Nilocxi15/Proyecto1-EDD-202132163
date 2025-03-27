#pragma once
#include <string>

using namespace std;

class QueueNode
{
private:
    string data;
    QueueNode *next;

public:
    // Constructor y destructor
    QueueNode(string data);
    ~QueueNode();

    // Getters
    string getData() const;
    QueueNode *getNext() const;

    // Setters
    void setData(string data);
    void setNext(QueueNode *next);
};