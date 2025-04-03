#include "GenerateMap.hpp"

DoubleLinkedList GenerateMap::generateMaze(int x, int y, int z) const
{
    DoubleLinkedList mazeList;

    for (int i = 0; i < z; i++)
    {
        SparseMatrix* maze = new SparseMatrix();
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= y; k++)
            {
                maze->insert(j, k, "X");
            }
        }
        maze->printMatrix();              

        mazeList.append(maze);
        // El error se genera en esta
    }

    return mazeList;
}