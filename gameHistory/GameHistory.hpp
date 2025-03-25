#pragma once
#include <iostream>
#include "../util/ReadFile.hpp"

using namespace std;

class GameHistory
{
private:
    ReadFile readFile;

public:
    void showGameHistory();
};
