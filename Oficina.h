#pragma once
#include "ET.h"
struct Oficina {
	EstacaoTrabalho* ets;
	int numero_ets;
	Carro* fila_espera;
	int fila_espera_tamanho;
	int ciclos;

};

Oficina criarOficina();