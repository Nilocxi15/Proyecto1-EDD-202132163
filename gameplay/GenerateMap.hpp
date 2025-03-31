#pragma once

#include "../doubleLinkedList/DoubleLinkedList.hpp"
#include "../sparseMatrix/SparseMatrix.hpp"

class GenerateMap
{
private:
    /* data */
public:
    DoubleLinkedList generateMaze(int x, int y, int z) const;
};