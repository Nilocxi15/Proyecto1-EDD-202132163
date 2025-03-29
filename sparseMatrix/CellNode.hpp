#pragma once

#include <string>

using namespace std;

class CellNode
{
private:
    int x;
    int y;
    string value;
    CellNode *up;
    CellNode *down;
    CellNode *left;
    CellNode *right;

public:
    // Constructor y destructor
    CellNode(int x, int y, string value);
    ~CellNode();

    // Getters
    int getX() const;
    int getY() const;
    string getValue() const;
    CellNode *getUp() const;
    CellNode *getDown() const;
    CellNode *getLeft() const;
    CellNode *getRight() const;

    // Setters
    void setX(int x);
    void setY(int y);
    void setValue(string value);
    void setUp(CellNode *up);
    void setDown(CellNode *down);
    void setLeft(CellNode *left);
    void setRight(CellNode *right);
};