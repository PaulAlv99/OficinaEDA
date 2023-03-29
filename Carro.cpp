#include "Carro.h"

Carro CriarCarro(string marca) {
	Carro novo_carro = Carro();
	novo_carro.marca = marca;

	return novo_carro;
}