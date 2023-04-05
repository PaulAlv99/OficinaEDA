#include "ET.h"

EstacaoTrabalho CriarET(int ID) {
	EstacaoTrabalho nova = EstacaoTrabalho();
	Carro carrinhos = Carro();
	nova.mecanico;
	nova.capacidade = 2 + (rand() % 3);
	nova.numero_carros = 0;
	nova.faturacao = 0;
	nova.ID = ID;
	nova.Carrosreparados = new string[10];
	nova.carros_a_ser_reparados = new string[nova.capacidade];
	return nova;
}

