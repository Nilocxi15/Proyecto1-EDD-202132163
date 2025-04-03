#pragma once

#include "../sparseMatrix/SparseMatrix.hpp"

class Node
{
private:
    SparseMatrix matrix;
    Node *next;
    Node *prev;

public:
    // Constructores y destructor
    Node(SparseMatrix matrix);
    ~Node();
    // Getters
    SparseMatrix getData() const;
    Node *getNext() const;
    Node *getPrev() const;

    // Setters
    void setData(SparseMatrix matrix);
    void setNext(Node *next);
    void setPrev(Node *prev);
};