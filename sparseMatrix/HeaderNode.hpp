#pragma once

#include "CellNode.hpp"

class HeaderNode
{
private:
    int id;
    HeaderNode *next;
    HeaderNode *prev;
    CellNode *access;

public:
    // Constructor y destructor
    HeaderNode(int id);
    ~HeaderNode();

    // Getters y Setters
    int getId() const;
    HeaderNode *getNext() const;
    HeaderNode *getPrev() const;
    CellNode *getAccess() const;

    //
    void setId(const int id);
    void setNext(HeaderNode *next);
    void setPrev(HeaderNode *prev);
    void setAccess(CellNode *access);
};