#include "ReadFile.hpp"

vector<string> ReadFile::read()
{
    ifstream file;
    string content;
    string tempContent;

    file.open("/home/jixcolin/Documentos/DocumentosUsac/EDD/Proyecto1/data/GameHistory.csv", ios::in);

    if (file.fail())
    {
        cout << "Error al abrir o leer el historial de partidas" << endl;
        exit(1);
    }

    while (!file.eof())
    {
        getline(file, tempContent);
        content += tempContent + "\n";
    }

    vector<string> dataPlayers = splitData(content);

    return dataPlayers;
}

void ReadFile::sortData()
{
    vector<string> data = read();
    int vectorSize = data.size();
    int mainVectorSize = vectorSize / 3;
    vector<vector<string>> dataPlayers(mainVectorSize);
    vector<string> tempData(3);

    for (int i = 0; i <= vectorSize; i++)
    {
        for (int i = 0; i < 3; i++)
        {
            string tempString = data[i];
            tempData.push_back(tempString);
        }
        
    }
}

vector<string> ReadFile::splitData(const string &data)
{
    vector<string> words;
    string word;

    for (char c : data)
    {
        if (c == ',' || c == '\n')
        {
            if (!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }

    if (!word.empty())
    {
        words.push_back(word);
    }

    return words;
}