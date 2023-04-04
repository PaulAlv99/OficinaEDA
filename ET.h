#pragma once
#include "Mecanico.h"
#include "Carro.h"
#include <string>
#include <iostream>
struct EstacaoTrabalho {
	Mecanico mecanico;
	int ID;
	int capacidade;
	//Carro* carros;
	int numero_carros;
	float faturacao;
	string* Listadeespera; 
	string* Carrosreparados;

};

EstacaoTrabalho CriarET(int ID);

