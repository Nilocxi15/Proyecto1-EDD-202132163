#pragma once

#include "HeadersList.hpp"
#include "CellNode.hpp"
#include "HeaderNode.hpp"

using namespace std;

class SparseMatrix
{
private:
    HeadersList rows;
    HeadersList columns;

public:
    // Constructor y destructor
    SparseMatrix();
    ~SparseMatrix();

    // Métodos
    void insert(int x, int y, string value);
    void rowIterator(int row);
    void columnIterator(int column);
    void printMatrix();

    // Getters
    string search(int x, int y) const;
};