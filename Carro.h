#pragma once
#include "ET.h"

using namespace std;

struct Carro {
	string marca;
	string modelo;
	int dias_em_reparacao;
	int tempo_reparacao_max;
	int ID;
	bool prioritario;

};

Carro CriarCarroRandom(string marca, string modelo);
Carro CriarCarro(Mecanico* mecanico, string modelo, int numero_ets);

void Adiciona(Carro*& v, int& tamanho, Carro& carro);
void Remove(Carro*& v, int& tamanho, int& ind);