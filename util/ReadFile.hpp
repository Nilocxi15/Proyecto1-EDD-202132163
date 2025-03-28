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

    vector<vector<string>> getVector();
    void setVector(const vector<vector<string>>& dataVector);

public:    
    void scoreSort();
    void nameSort();

    void loadData();
    void clearData();
};