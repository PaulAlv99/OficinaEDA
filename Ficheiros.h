#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

struct LinhasFicheiro {
	int tamanho;
	string* linhas;
};

LinhasFicheiro CarregarFicheirosLista(string Nome_Ficheiro);
int TamanhoFicheiro(string Nome_Ficheiro);