#pragma once
#include "ET.h"

struct Oficina {
	EstacaoTrabalho* ets;
	int numero_ets;
	Carro* fila_espera;
	int fila_espera_tamanho;
	int ciclos;

};

Oficina criarOficina(LinhasFicheiro &marcas, LinhasFicheiro &modelos);

void seguinte(Oficina& Of);

void reparacao(EstacaoTrabalho ID1, Oficina METAL, Carro ID2);

void CriarCarrosNaFila(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos, int num);