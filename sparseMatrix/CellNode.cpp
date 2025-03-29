#include "CellNode.hpp"

// Constructor y destructor
CellNode::CellNode(int x, int y, string value)
{
    this->x = x;
    this->y = y;
    this->value = value;
    this->up = nullptr;
    this->down = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

CellNode::~CellNode()
{
    // Destructor
}

// Getters
int CellNode::getX() const
{
    return x;
}

int CellNode::getY() const
{
    return y;
}

string CellNode::getValue() const
{
    return value;
}

CellNode *CellNode::getUp() const
{
    return up;
}

CellNode *CellNode::getDown() const
{
    return down;
}

CellNode *CellNode::getLeft() const
{
    return left;
}

CellNode *CellNode::getRight() const
{
    return right;
}

// Setters
void CellNode::setX(int x)
{
    this->x = x;
}

void CellNode::setY(int y)
{
    this->y = y;
}

void CellNode::setValue(string value)
{
    this->value = value;
}

void CellNode::setUp(CellNode *up)
{
    this->up = up;
}

void CellNode::setDown(CellNode *down)
{
    this->down = down;
}

void CellNode::setLeft(CellNode *left)
{
    this->left = left;
}

void CellNode::setRight(CellNode *right)
{
    this->right = right;
}