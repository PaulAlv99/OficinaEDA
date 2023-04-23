#include "Ficheiros.h"


int TamanhoFicheiro(string Nome_Ficheiro) {
    int numero_linhas = 0;
    string line;
    ifstream file(Nome_Ficheiro);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            numero_linhas++;
        }
        file.close();
    }
    return numero_linhas;
}
LinhasFicheiro CarregarFicheirosLista(string Nome_Ficheiro) {

    LinhasFicheiro novo = LinhasFicheiro();

    string* linhas = new string[TamanhoFicheiro(Nome_Ficheiro)];

    string line;

    ifstream file(Nome_Ficheiro);
    if (file.is_open())
    {
        for (int i = 0; i < TamanhoFicheiro(Nome_Ficheiro);i++)
        {
            getline(file, line);
            linhas[i] = line;
        }
        file.close();
    }

    novo.tamanho = TamanhoFicheiro(Nome_Ficheiro);
    novo.linhas = linhas;

    return novo;
}
