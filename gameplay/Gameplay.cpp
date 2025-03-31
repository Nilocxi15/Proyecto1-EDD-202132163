#include "Gameplay.hpp"

void gameplay::startGame()
{
    int x = 0;
    int y = 0;
    int z = 0;
    bool optionIsCorrect = false;

    system("clear");
    this->playerName = "";
    this->playerScore = 0;
    this->playerMoves = 0;
    this->playerHealth = 100;

    cout << "---------- INICIANDO EL JUEGO ----------" << endl;
    cout << "Ingrese su nombre: ";
    cin >> this->playerName;

    do
    {
        cout << "Ingrese las dimensiones del laberinto (x, y, z): ";

        try
        {
            cin >> x >> y >> z;
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

        if (x < 2 || y < 2 || z < 2)
        {
            system("clear");
            cout << "ERROR. Las dimensiones del laberinto deben ser mayor o igual a 2x2x2" << endl;
            continue;
        }

        optionIsCorrect = true;

    } while (!optionIsCorrect);

    this->startTime = chrono::system_clock::now();

    displayMaze(x, y, z);
}

void gameplay::displayMaze(int x, int y, int z)
{
    SparseMatrix temporalMaze;
    GenerateMap map;

    DoubleLinkedList mazeList = map.generateMaze(x, y, z);
    int currentMaze = 1;
    int moveOption = 0;

    

    do
    {
        system("clear");
        cout << "---------- JUGANDO ----------" << endl;
        cout << "Salud: " << this->playerHealth << endl;
        cout << "Usted se encuentra en el laberinto " << currentMaze << "\n\n"
             << endl;
        
        cout << "\n\n"
             << "---------- OPCIONES ----------" << endl;
        cout << "1. Moverse arriba" << endl;
        cout << "2. Moverse abajo" << endl;
        cout << "3. Moverse izquierda" << endl;
        cout << "4. Moverse derecha" << endl;
        cout << "5. Moverse adelante" << endl;
        cout << "6. Moverse atras" << endl;

        try
        {
            cin >> moveOption;
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

        switch (moveOption)
        {
        case 1:
            playerMoves++;
            break;
        case 2:
            playerMoves++;
            break;
        case 3:
            playerMoves++;
            break;
        case 4:
            playerMoves++;
            break;
        case 5:
            playerMoves++;
            break;
        case 6:
            playerMoves++;
            break;
        default:
            currentMaze++;
            break;
        }

        playerHealth = playerHealth - 10;

    } while (playerHealth > 0);

    system("clear");
    cout << "---------- GAME OVER ----------" << endl;
    this->endTime = chrono::system_clock::now();
    this->elapsedTime = chrono::duration_cast<chrono::seconds>(this->endTime - this->startTime);

    // int elapsedTimeInSeconds = static_cast<int>(this->elapsedTime.count());
    // int minutes = elapsedTimeInSeconds / 60;
    // int seconds = elapsedTimeInSeconds % 60;
}