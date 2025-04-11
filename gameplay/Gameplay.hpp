#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <limits>
#include <stdexcept>
#include <fstream>

#include "../sparseMatrix/SparseMatrix.hpp"
#include "GenerateMap.hpp"
#include "../queue/Queue.hpp"
#include "../util/BoxesDistance.hpp"
#include "../util/ReadFile.hpp"

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
    void saveGameHistory(int elapsedTimeInSeconds) const;
    void showResults(int elapsedTimeInSeconds, int trapsAndEnemies, int hints, string treasurePosition);
    GameElement verifyBoxes(int posX, int posY, int posZ, vector<GameElement> *elementsVector) const;

public:
    void startGame();
};