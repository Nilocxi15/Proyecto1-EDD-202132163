#include <iostream>
#include <limits>
#include <stdexcept>

#include "./gameHistory/GameHistory.hpp"

using namespace std;

int main()
{

    GameHistory gameHistory;

    bool optionIsCorrect = false;
    int option = 0;

    do
    {
        cout << "---------- BIENVENIDO AL JUEGO DEL LABERINTO ----------" << endl;
        cout << "Menu de opciones:" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Historial de partidas" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese la opcion deseada: ";

        try
        {
            cin >> option;
            if (cin.fail())
            {
                throw runtime_error(" Tipo de dato incorrecto\n");
            }
        }
        catch (const std::exception &e)
        {
            system("clear");
            cout << "ERROR." << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (option)
        {
        case 1:
            cout << "Iniciando el juego..." << endl;
            /* code */
            break;
        case 2:
            system("clear");
            gameHistory.showGameHistory();
            break;
        case 3:
            cout << "Saliendo del juego..." << endl;
            optionIsCorrect = true;
            system("clear");
            break;
        default:
            system("clear");
            cout << "ERROR. Opcion no valida" << endl;
            break;
        }

    } while (!optionIsCorrect);

    return 0;
}