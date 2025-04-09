#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

#include "../doubleLinkedList/DoubleLinkedList.hpp"
#include "../sparseMatrix/SparseMatrix.hpp"
#include "../models/GameElement.hpp"

class GenerateMap
{
private:
    vector<GameElement> *specialBoxes = new vector<GameElement>();

public:
    DoubleLinkedList generateMaze(int x, int y, int z) const;
    vector<GameElement> *getVector() const;
};