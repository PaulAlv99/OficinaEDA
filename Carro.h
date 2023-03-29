#pragma once
#include "ET.h"

using namespace std;
struct Carro {
	string marca;
	string modelo;
	int dias_em_reparacao;
	bool prioritario;
};

Carro CriarCarro(string marca);