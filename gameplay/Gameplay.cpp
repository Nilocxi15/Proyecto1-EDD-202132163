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
    // VerifyBoxes verifyBoxes;
    SparseMatrix *temporalMaze;
    GenerateMap map;

    DoubleLinkedList mazeList = map.generateMaze(x, y, z);
    vector<GameElement> *specialBoxes = map.getVector();

    int currentMaze = 1;
    int moveOption = 0;
    int halfSize = mazeList.length() / 2;
    int posX = 1;
    int posY = 1;

    temporalMaze = mazeList.getFirst();

    do
    {
        system("clear");
        cout << "---------- JUGANDO ----------" << endl;
        cout << "Salud: " << this->playerHealth << endl;
        cout << "Usted se encuentra en el laberinto " << currentMaze << "\n\n"
             << endl;
        temporalMaze->printMatrix();
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
            if (posY == 1)
            {
                cout << "No se puede mover hacia arriba, ya no hay casillas en esa direccion" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                continue;
            }
            temporalMaze->editValueLU(posX, posY, ".");
            posY--;
            temporalMaze->editValueLU(posX, posY, "J");
            playerMoves++;
            break;
        case 2:
            if (posY == y)
            {
                cout << "No se puede mover hacia abajo, ya no hay casillas en esa direccion" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                continue;
            }
            temporalMaze->editValueRD(posX, posY, ".");
            posY++;
            temporalMaze->editValueRD(posX, posY, "J");
            playerMoves++;
            break;
        case 3:
            if (posX == 1)
            {
                cout << "No se puede mover hacia la izquierda, ya no hay casillas en esa direccion" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                continue;
            }
            temporalMaze->editValueLU(posX, posY, ".");
            posX--;
            temporalMaze->editValueLU(posX, posY, "J");
            playerMoves++;
            break;
        case 4:
            if (posX == x)
            {
                cout << "No se puede mover hacia la derecha, ya no hay casillas en esa direccion" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                continue;
            }
            temporalMaze->editValueRD(posX, posY, ".");
            posX++;
            temporalMaze->editValueRD(posX, posY, "J");
            playerMoves++;
            break;
        case 5:
        {
            if (currentMaze == mazeList.length())
            {
                cout << "No se puede avanzar, ya no hay laberintos adelante" << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (currentMaze <= halfSize)
            {
                temporalMaze->editValueRD(posX, posY, ".");
                temporalMaze = mazeList.getNext(currentMaze);
                temporalMaze->editValueRD(posX, posY, "J");
                currentMaze++;
            }
            else if (currentMaze > halfSize)
            {
                temporalMaze->editValueRD(posX, posY, ".");
                int iterator = mazeList.length() - currentMaze;
                temporalMaze = mazeList.getPrev(iterator);
                temporalMaze->editValueRD(posX, posY, "J");
                currentMaze++;
            }
            playerMoves++;
            break;
        }
        case 6:
            if (currentMaze == 1)
            {
                cout << "No se puede retroceder, ya no hay laberintos atras" << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (currentMaze <= halfSize)
            {
                temporalMaze->editValueLU(posX, posY, ".");
                int prevMaze = currentMaze - 2;
                temporalMaze = mazeList.getNext(prevMaze);
                temporalMaze->editValueLU(posX, posY, "J");
                currentMaze--;
            }
            else if (currentMaze > halfSize)
            {
                temporalMaze->editValueLU(posX, posY, ".");
                int iterator = mazeList.length() - currentMaze + 2;
                temporalMaze = mazeList.getPrev(iterator);
                temporalMaze->editValueLU(posX, posY, "J");
                currentMaze--;
            }
            playerMoves++;
            break;
        default:
            cout << "Opcion no valida, por favor intente de nuevo" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            break;
        }

        GameElement tempBox = verifyBoxes(posX, posY, currentMaze - 1, specialBoxes);

        // Verificación de casillas especiales

        if (tempBox.getName() != "")
        {
            if (tempBox.getName() == "ENEMIGO")
            {
                playerHealth = playerHealth - tempBox.getActionPoints();
                cout << "Se ha encontrado un enemigo, usted ha perdido " << tempBox.getActionPoints() << " de salud" << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (tempBox.getName() == "TRAMPA")
            {
                playerHealth = playerHealth - tempBox.getActionPoints();
                cout << "Se ha encontrado una trampa, usted ha perdido " << tempBox.getActionPoints() << " de salud" << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (tempBox.getName() == "POCION")
            {
                playerHealth = playerHealth + tempBox.getActionPoints();
                cout << "Se ha encontrado con una pocion, usted ha ganado " << tempBox.getActionPoints() << " de salud" << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (tempBox.getName() == "PISTA")
            {
                cout << "Usted ha encontrado una pista" << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }
            else if (tempBox.getName() == "TESORO")
            {
                cout << "Se ha encontrado el tesoro" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                break;
            }

            for (size_t i = 0; i < specialBoxes->size(); i++)
            {
                if (tempBox.getPosX() == specialBoxes->at(i).getPosX() && tempBox.getPosY() == specialBoxes->at(i).getPosY() && tempBox.getPosZ() == specialBoxes->at(i).getPosZ())
                {
                    specialBoxes->erase(specialBoxes->begin() + i);
                    
                }
            }
            
        }
        

    } while (playerHealth > 0);

    system("clear");
    cout << "---------- GAME OVER ----------" << endl;
    this->endTime = chrono::system_clock::now();
    this->elapsedTime = chrono::duration_cast<chrono::seconds>(this->endTime - this->startTime);

    // int elapsedTimeInSeconds = static_cast<int>(this->elapsedTime.count());
    // int minutes = elapsedTimeInSeconds / 60;
    // int seconds = elapsedTimeInSeconds % 60;
}

GameElement gameplay::verifyBoxes(int posX, int posY, int posZ, vector<GameElement> *elementsVector) const
{

    for (const auto &element : *elementsVector)
    {
        if (element.getPosX() == posX && element.getPosY() == posY && element.getPosZ() == posZ)
        {
            GameElement elementFound = element;            
            return element;
        }
    }

    return GameElement("", 0, 0, 0, 0);
}