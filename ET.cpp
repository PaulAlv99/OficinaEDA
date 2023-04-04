#include "ET.h"

EstacaoTrabalho CriarET(int ID) {
	EstacaoTrabalho nova = EstacaoTrabalho();
	nova.mecanico;
	nova.capacidade = (rand() % 5 + 2);
	//nova.carros = new  Carro[0];
	nova.numero_carros = 0;
	nova.faturacao = 0;
	nova.ID = ID;
	nova.Listadeespera;
	nova.Carrosreparados;

	return nova;
}

