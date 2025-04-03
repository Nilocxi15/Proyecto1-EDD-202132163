#include "ReadFile.hpp"

void ReadFile::scoreSort()
{
    if (mainVector.empty())
    {
        cout << "No hay datos en el vector" << endl;
        return;
    }
    else
    {
        for (size_t i = 1; i < mainVector.size(); ++i)
        {
            vector<string> key = mainVector[i];
            int j = i - 1;

            while (j >= 0 && stoi(mainVector[j][1]) < stoi(key[1]))
            {
                mainVector[j + 1] = mainVector[j];
                j--;
            }
            mainVector[j + 1] = key;
        }

        system("clear");
        cout << "---------- HISTORIAL DE PARTIDAS ORDENADO POR PUNTAJE ----------" << endl;
        cout << "Nombre\t\tPuntaje\t\tMovimientos\t\tTiempo (mins)" << endl;
        for (const auto &row : mainVector)
        {
            cout << row[0] << "\t\t" << row[1] << "\t\t" << row[2] << "\t\t" << row[3] << endl;
        }
    }
}

void ReadFile::nameSort()
{
    if (mainVector.empty())
    {
        cout << "No hay datos en el vector" << endl;
        return;
    }
    else
    {
        for (size_t i = 1; i < mainVector.size(); ++i)
        {
            vector<string> key = mainVector[i];
            int j = i - 1;

            while (j >= 0 && mainVector[j][0] > key[0])
            {
                mainVector[j + 1] = mainVector[j];
                j--;
            }
            mainVector[j + 1] = key;
        }

        system("clear");
        cout << "---------- HISTORIAL DE PARTIDAS ORDENADO POR PUNTAJE ----------" << endl;
        cout << "Nombre\t\tPuntaje\t\tMovimientos\t\tTiempo (mins)" << endl;
        for (const auto &row : mainVector)
        {
            cout << row[0] << "\t\t" << row[1] << "\t\t" << row[2] << "\t\t" << row[3] << endl;
        }
    }
}

void ReadFile::loadData()
{
    ifstream file;
    string fileContent;

    vector<string> temporalString(4);

    file.open("/home/jixcolin/Documentos/DocumentosUsac/EDD/Proyecto1/data/GameHistory.csv", ios::in);

    if (file.fail())
    {
        cout << "Error al abrir o leer el archivo" << endl;
        exit(1);
    }

    while (!file.eof())
    {
        getline(file, fileContent);
        stringstream ss(fileContent);
        string item;
        int index = 0;

        while (getline(ss, item, ',') && index < 4)
        {
            temporalString[index] = item;
            index++;
        }

        for (const auto &str : temporalString)
        {
            queue.enqueue(str);
        }
    }

    int mainVectorSize = queue.length() / 4;
    vector<vector<string>> dataVector(mainVectorSize, vector<string>(4));

    for (int i = 0; i < mainVectorSize; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temporalString[j] = queue.dequeue();
        }
        dataVector[i] = temporalString;
    }

    if (dataVector.empty())
    {
        cout << "No hay datos en el vector" << endl;
    }
    else
    {
        this->mainVector = dataVector;
    }

    file.close();
}

void ReadFile::clearData()
{
    queue.clear();
}