#include "gameplay.hpp"

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

    //displayMaze(x, y, z);

    /*

    PARTE EN LA QUE SE HACE LA COMPARACIÓN DEL TIEMPO TRANSCURRIDO DURANTE EL JUEGO

    if (this->playerMoves == 1)
    {
        this->endTime = chrono::system_clock::now();
        this->elapsedTime = chrono::duration_cast<chrono::seconds>(this->endTime - this->startTime);
        cout << "Tiempo transcurrido: " << this->elapsedTime.count() << " segundos" << endl;
    }
    */
}

void gameplay::displayMaze(int x, int y, int z)
{
    cout << "Dimensiones del laberinto: " << x << " " << y << " " << z << endl;
    /*
    do
    {
        
    } while (playerHealth > 0);
    
    system("clear");
    cout << "---------- GAME OVER ----------" << endl;
    this->endTime = chrono::system_clock::now();
    this->elapsedTime = chrono::duration_cast<chrono::seconds>(this->endTime - this->startTime);

    int elapsedTimeInSeconds = static_cast<int>(this->elapsedTime.count());
    int minutes = elapsedTimeInSeconds / 60;
    //int seconds = elapsedTimeInSeconds % 60;
    */
}