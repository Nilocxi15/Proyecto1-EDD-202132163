#include "GenerateMap.hpp"

DoubleLinkedList GenerateMap::generateMaze(int x, int y, int z) const
{
    DoubleLinkedList mazeList;

    // Inicializar el puntero specialBoxes

    int mainProb, subProb;
    int totalSize = x * y;
    int availableBoxes = totalSize * (((float)50) / ((float)100));
    availableBoxes--;

    int posX = rand() % x + 1;
    int posY = rand() % y + 1;
    int posZ = rand() % z;

    for (int i = 0; i < z; i++)
    {
        int tempCounter = availableBoxes;
        SparseMatrix *maze = new SparseMatrix();
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= y; k++)
            {
                if (i == 0 && j == 1 && k == 1)
                {
                    maze->insert(j, k, "J");
                    continue;
                }

                if (j == posX && k == posY && i == posZ)
                {
                    maze->insert(j, k, ".");
                    specialBoxes->push_back(GameElement("TESORO", j, k, i, 0));
                    continue;
                }

                mainProb = rand() % 10 + 1;
                if (mainProb <= 7)
                {
                    maze->insert(j, k, ".");
                }
                else if (tempCounter > 0)
                {
                    subProb = rand() % 11 + 1;

                    if (subProb <= 3)
                    {
                        maze->insert(j, k, ".");
                        int damage = rand() % 10 + 5;
                        specialBoxes->push_back(GameElement("ENEMIGO", j, k, i, damage));
                        tempCounter--;
                    }
                    else if (subProb > 3 && subProb <= 6)
                    {
                        maze->insert(j, k, ".");
                        int damage = rand() % 10 + 1;
                        specialBoxes->push_back(GameElement("TRAMPA", j, k, i, damage));
                        tempCounter--;
                    }
                    else if (subProb > 6 && subProb <= 9)
                    {
                        maze->insert(j, k, ".");
                        int heal = rand() % 10 + 1;
                        specialBoxes->push_back(GameElement("POCION", j, k, i, heal));
                        tempCounter--;
                    }
                    else if (subProb > 9 && subProb <= 11)
                    {
                        int diffX = abs(posX - j);
                        int diffY = abs(posY - k);
                        int diffZ = abs(posZ - i);
                        maze->insert(j, k, "P");

                        if (diffX <= 1 && diffY <= 1 && diffZ <= 1)
                        {
                            specialBoxes->push_back(GameElement("PISTA", j, k, i, 1));
                        }
                        else if (diffX <= 2 && diffY <= 2 && diffZ <= 2)
                        {
                            specialBoxes->push_back(GameElement("PISTA", j, k, i, 2));
                        }
                        else
                        {
                            specialBoxes->push_back(GameElement("PISTA", j, k, i, 3));
                        }

                        tempCounter--;
                    }
                }
                else
                {
                    maze->insert(j, k, ".");
                }
            }
        }

        mazeList.append(maze);
    }

        

    return mazeList;
}

vector<GameElement> *GenerateMap::getVector() const
{
    return this->specialBoxes;
}