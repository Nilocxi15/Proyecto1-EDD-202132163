#include "ReadFile.hpp"

void ReadFile::test()
{
    for (int i = 0; i < 10; i++)
    {
        queue.enqueue(to_string(i));
    }

    queue.print();
}

void ReadFile::loadData()
{
    ifstream file;
    string fileContent;

    vector<string> temporalString(3);

    file.open("/home/jixcolin/Documentos/UNIVERSIDAD/EDD/Proyecto1-EDD-202132163/data/GameHistory.csv", ios::in);

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

        while (getline(ss, item, ',') && index < 3)
        {
            temporalString[index] = item;
            index++;
        }

        for (const auto &str : temporalString)
        {
            queue.enqueue(str);
        }
    }

    int mainVectorSize = queue.length() / 3;
    vector<vector<string>> dataVector(mainVectorSize, vector<string>(3));
    
    for (int i = 0; i < mainVectorSize; i++)
    {
        for (int i = 0; i < 3; i++)
        {
            temporalString[i] = queue.dequeue();
        }
        dataVector[i] = temporalString;
    }
    
    for (const auto &row : dataVector)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    //mainVector = dataVector;

    file.close();
}

void ReadFile::clearData()
{
    queue.clear();
}