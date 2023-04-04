#include "Ficheiros.h"

LinhasFicheiro CarregarFicheirosLista(string Nome_Ficheiro) {
    int indice = 0;

    LinhasFicheiro novo = LinhasFicheiro();

    string* linhas = new string[TamanhoFicheiro(Nome_Ficheiro)];

    string line;
    ifstream file(Nome_Ficheiro);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            linhas[indice] = line;
            indice++;
        }
        file.close();
    }

    novo.tamanho = TamanhoFicheiro(Nome_Ficheiro);
    novo.linhas = linhas;


    return novo;
}

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