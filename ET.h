#pragma once
#include "Mecanico.h"
#include "Carro.h"
#include <string>
#include <iostream>
struct EstacaoTrabalho {
	Mecanico mecanico = Mecanico();
	int ID = 0;
	int capacidade = 0;
	float faturacao = 0;
	listacarros* carros_a_ser_reparados;
	int num_carros_a_ser_reparados = 0;
	listacarros* Carrosreparados;
	int num_carros_reparados = 0;
	EstacaoTrabalho* seguinte;
	EstacaoTrabalho* inicio;
};

EstacaoTrabalho CriarET(int ID);
void reparacao(EstacaoTrabalho& ID1);

