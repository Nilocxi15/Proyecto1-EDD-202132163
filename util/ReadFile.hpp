#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

#include "../queue/Queue.hpp"

using namespace std;

class ReadFile
{
private:
    Queue queue;
    vector<vector<string>> mainVector;

public:
    void test();
    void scoreSort();
    void nameSort();

    void loadData();
    void clearData();
};