#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "Node.hpp"
#include "../sparseMatrix/SparseMatrix.hpp"

using namespace std;

class DoubleLinkedList
{
private:
    int size = 0;
    Node *head;
    Node *tail;
    int id = 0;

public:
    // Constructor y destructor
    DoubleLinkedList();
    ~DoubleLinkedList();

    // Getters
    int length() const;
    SparseMatrix getNext(int iterator) const;
    SparseMatrix getPrev(int iterator) const;
    SparseMatrix getFirst() const;

    // Métodos
    void append(const SparseMatrix &sparseMatrix);
};