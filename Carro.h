#pragma once
#include "Ficheiros.h"
#include <string>

using namespace std;

struct Carro {
	string marca = "";
	string modelo = "";
	int dias_em_reparacao = 0;
	int tempo_reparacao_max = 0;
	int ID = 0;
	bool prioritario = 0;
	int custoreparacao = 0;

};

struct listacarros {
	Carro carro;
	listacarros* seguinte = NULL;
	listacarros* inicio = NULL;
};


Carro CriarCarro(LinhasFicheiro& marcas, LinhasFicheiro& modelos);
bool  GerarProbalidades(double probalidade);
void Adiciona(Carro*& v, int& tamanho, Carro& carro);
void Remove(Carro*& v, int& tamanho, int& ind);
void adicionarcarro(listacarros& lista, Carro& carro);
