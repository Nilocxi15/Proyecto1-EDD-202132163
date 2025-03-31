#include "SparseMatrix.hpp"

// Constructor y destructor
SparseMatrix::SparseMatrix() : rows("row"), columns("column") {}

SparseMatrix::~SparseMatrix() {}

SparseMatrix::SparseMatrix(const SparseMatrix &other) : rows("row"), columns("column")
{
    for (int i = 1; i <= other.rows.length(); i++)
    {
        HeaderNode *rowHeader = other.rows.get(i);
        if (rowHeader != nullptr)
        {
            CellNode *current = rowHeader->getAccess();
            while (current != nullptr)
            {
                // Insertar cada celda en la nueva matriz
                this->insert(current->getX(), current->getY(), current->getValue());
                current = current->getRight();
            }
        }
    }
}

// Metodos
void SparseMatrix::insert(int x, int y, string value)
{
    CellNode *newNode = new CellNode(x, y, value);
    HeaderNode *cell_x = rows.get(x);
    HeaderNode *cell_y = columns.get(y);

    if (cell_x == nullptr)
    {
        cell_x = new HeaderNode(x);
        rows.add(cell_x);
    }

    if (cell_y == nullptr)
    {
        cell_y = new HeaderNode(y);
        columns.add(cell_y);
    }

    // Insertar en la fila
    if (cell_x->getAccess() == nullptr)
    {
        cell_x->setAccess(newNode);
    }
    else
    {
        if (newNode->getY() < cell_x->getAccess()->getY())
        {
            newNode->setRight(cell_x->getAccess());
            cell_x->getAccess()->setLeft(newNode);
            cell_x->setAccess(newNode);
        }
        else
        {
            CellNode *temp = cell_x->getAccess();
            while (temp != nullptr)
            {
                if (newNode->getY() < temp->getY())
                {
                    newNode->setRight(temp);
                    newNode->setLeft(temp->getLeft());
                    temp->getLeft()->setRight(newNode);
                    temp->setLeft(newNode);
                    break;
                }
                else if (temp->getRight() == nullptr)
                {
                    temp->setRight(newNode);
                    newNode->setLeft(temp);
                    break;
                }
                else
                {
                    temp = temp->getRight();
                }
            }
        }
    }

    // Insertar en la columna
    if (cell_y->getAccess() == nullptr)
    {
        cell_y->setAccess(newNode);
    }
    else
    {
        if (newNode->getX() < cell_y->getAccess()->getX())
        {
            newNode->setDown(cell_y->getAccess());
            cell_y->getAccess()->setUp(newNode);
            cell_y->setAccess(newNode);
        }
        else
        {
            CellNode *temp = cell_y->getAccess();
            while (temp != nullptr)
            {
                if (newNode->getX() < temp->getX())
                {
                    newNode->setDown(temp);
                    newNode->setUp(temp->getUp());
                    temp->getUp()->setDown(newNode);
                    temp->setUp(newNode);
                    break;
                }
                else if (temp->getDown() == nullptr)
                {
                    temp->setDown(newNode);
                    newNode->setUp(temp);
                    break;
                }
                else
                {
                    temp = temp->getDown();
                }
            }
        }
    }
}

void SparseMatrix::rowIterator(int row)
{
    cout << "--------------Recorrido por fila------------------" << endl;
    HeaderNode *cell = rows.get(row);
    if (cell == nullptr)
    {
        cout << "La fila " << row << " no existe" << endl;
        return;
    }

    CellNode *temp = cell->getAccess();
    while (temp != nullptr)
    {
        cout << "x: " << temp->getX() << " y: " << temp->getY() << " value: " << temp->getValue() << endl;
        temp = temp->getRight();
    }
}

void SparseMatrix::columnIterator(int column)
{
    cout << "--------------Recorrido por columna------------------" << endl;
    HeaderNode *cell = columns.get(column);
    if (cell == nullptr)
    {
        cout << "La columna " << column << " no existe" << endl;
        return;
    }

    CellNode *temp = cell->getAccess();
    while (temp != nullptr)
    {
        cout << "x: " << temp->getX() << " y: " << temp->getY() << " value: " << temp->getValue() << endl;
        temp = temp->getDown();
    }
}

// Getters
string SparseMatrix::search(int x, int y) const
{
    HeaderNode *row = rows.get(x);
    if (row == nullptr)
    {
        return "";
    }

    CellNode *temp = row->getAccess();
    while (temp != nullptr)
    {
        if (temp->getY() == y)
        {
            return temp->getValue();
        }
        temp = temp->getRight();
    }

    return "";
}

void SparseMatrix::printMatrix()
{
    cout << "--------------Matriz dispersa------------------" << endl;
    for (int i = 1; i <= rows.length(); i++)
    {
        for (int j = 1; j <= columns.length(); j++)
        {
            cout << search(i, j) << "\t";
        }
        cout << endl;
    }
}