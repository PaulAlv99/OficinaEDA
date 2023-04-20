#pragma once
#include "Mecanico.h"
#include "Carro.h"
#include <string>
#include <iostream>
struct EstacaoTrabalho {
	Mecanico mecanico;
	int ID;
	int capacidade;
	int numero_carros;
	float faturacao;
	Carro* carros_a_ser_reparados; //arrays de carros
	string* Carrosreparados;

};

EstacaoTrabalho CriarET(int ID);

