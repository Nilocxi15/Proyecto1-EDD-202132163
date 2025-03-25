#include "GameHistory.hpp"

void GameHistory::showGameHistory()
{
    cout << "---------- HISTORIAL DE PARTIDAS ----------" << endl;
    readFile.sortData();
}