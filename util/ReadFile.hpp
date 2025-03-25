#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class ReadFile
{
private:
    vector<string> read();
    vector<string> splitData(const string &data);

public:
    void sortData();
};