#include "Carro.h"
#include <string>
Carro CriarCarroRandom(string marca, string modelo) {
	Carro novo_carro = Carro();
	novo_carro.marca = marca;
	novo_carro.modelo = modelo;
	novo_carro.ID = 0;
	novo_carro.tempo_reparacao_max = 2 + (rand() % 3);
	novo_carro.dias_em_reparacao = 0;
	novo_carro.prioritario = false;
	return novo_carro;
}

Carro CriarCarro(string marca, string modelo) {
	Carro novo_carro = Carro();
	novo_carro.marca = marca;
	novo_carro.modelo = modelo;
	novo_carro.ID = 0;
	novo_carro.tempo_reparacao_max = 2 + (rand() % 3);
	novo_carro.dias_em_reparacao = 0;
	novo_carro.prioritario = false;
	return novo_carro;
}