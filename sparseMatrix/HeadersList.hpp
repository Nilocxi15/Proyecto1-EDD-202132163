#pragma once

#include <iostream>

#include "HeaderNode.hpp"

using namespace std;

class HeadersList
{
private:
    string type;
    HeaderNode *first;
    HeaderNode *last;
    int size;

public:
    // Constructor y destructor
    HeadersList(const string type);
    ~HeadersList();

    // Getters
    int length() const;
    HeaderNode *get(int id) const;

    // Setters
    void setType(const string type);

    // Métodos
    void add(HeaderNode *newNode);
    void print();
};