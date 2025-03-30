#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <limits>
#include <stdexcept>

#include "../sparseMatrix/SparseMatrix.hpp"

using namespace std;

class gameplay
{
private:
    SparseMatrix matrix;

    string playerName;

    int playerScore;
    int playerMoves;
    int playerHealth;

    chrono::time_point<chrono::system_clock> startTime;
    chrono::time_point<chrono::system_clock> endTime;
    chrono::duration<long, ratio<1>> elapsedTime;

    void displayMaze(int x, int y, int z);
    void generateMaze();

public:
    void startGame();
};