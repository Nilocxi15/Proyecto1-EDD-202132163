#include "GenerateMap.hpp"

DoubleLinkedList GenerateMap::generateMaze(int x, int y, int z) const
{
    DoubleLinkedList mazeList;

    int mainProb, subProb;
    int totalSize = x * y;
    int availableBoxes = totalSize * (((float)50) / ((float)100));
    availableBoxes--;

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

                mainProb = rand() % 10 + 1;
                if (mainProb <= 7)
                {
                    maze->insert(j, k, ".");
                }
                else if (tempCounter > 0)
                {
                    subProb = rand() % 10 + 1;

                    if (subProb <= 3)
                    {
                        maze->insert(j, k, "E");
                        tempCounter--;
                    }
                    else if (subProb > 3 && subProb <= 6)
                    {
                        maze->insert(j, k, "T");
                        tempCounter--;
                    }
                    else if (subProb > 6 && subProb <= 9)
                    {
                        maze->insert(j, k, "P");
                        tempCounter--;
                    }
                    else if (subProb == 10)
                    {
                        maze->insert(j, k, "O");
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