#pragma once
#include "Mecanico.h"
#include "Carro.h"
struct EstacaoTrabalho {
	Mecanico mecanico;
	int ID;
	int capacidade;
	//Carro* carros;
	int numero_carros;
	float faturacao;
};

EstacaoTrabalho CriarET(int ID);
