#include "ET.h"

EstacaoTrabalho CriarET(int ID) {
	EstacaoTrabalho nova = EstacaoTrabalho();
	Carro carrinhos = Carro();
	nova.mecanico;
	nova.capacidade = 2 + (rand() % 3);
	nova.numero_carros = 0;
	nova.faturacao = 0;
	nova.ID = ID;
	nova.Carrosreparados = new Carro[0];
	nova.carros_a_ser_reparados = new Carro[nova.capacidade];
	nova.num_carros_a_ser_reparados = 0;
	return nova;
}

