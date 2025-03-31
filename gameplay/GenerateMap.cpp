#include "GenerateMap.hpp"

DoubleLinkedList GenerateMap::generateMaze(int x, int y, int z) const
{
    DoubleLinkedList mazeList;

    for (int i = 0; i < z; i++)
    {
        SparseMatrix maze;
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= y; k++)
            {
                maze.insert(j, k, "X");
            }
        }
    }

    return mazeList;
}