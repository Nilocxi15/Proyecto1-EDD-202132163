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
    HeadersList(string type);
    ~HeadersList();

    // Metodos
    void add(HeaderNode *newNode);
    void print();

    // Getters
    int length() const;
    HeaderNode *get(int id) const;
    HeaderNode *getFirst() const;

    // Setters
    void setType(string type);
};