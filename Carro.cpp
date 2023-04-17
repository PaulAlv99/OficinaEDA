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

Carro CriarCarro(Mecanico *mecanico,string modelo, int numero_ets) {
	Carro novo_carro = Carro();
	LinhasFicheiro ficheiros = LinhasFicheiro();
	Mecanico Mecanicos = Mecanico();
	novo_carro.marca = mecanico[rand() % numero_ets].marca;
	novo_carro.modelo = modelo;
	novo_carro.ID = 0;
	novo_carro.tempo_reparacao_max = 2 + (rand() % 3);
	novo_carro.dias_em_reparacao = 0;
	novo_carro.prioritario = false;
	return novo_carro;
}

void Adiciona(Carro*& v, int& tamanho, Carro& carro)
{
	int tamanho_novo = tamanho + 1;
	Carro* novo = new Carro[tamanho_novo];
	for (int i = 0; i < tamanho; i++) {
		novo[i] = v[i];
	}
	novo[tamanho] = carro;

	delete[] v;

	v = novo;

}

void Remove(Carro*& v, int& tamanho, int& ind)
{
	int tamanho_novo = tamanho - 1;
	Carro* novo = new Carro[tamanho_novo];
	for (int i = 0; i < ind; i++) {
		novo[i] = v[i];
	}
	for (int i = ind; i < tamanho_novo; i++) {
		novo[i] = v[i + 1];
	}

	delete[] v;
	novo = v;
	

}
