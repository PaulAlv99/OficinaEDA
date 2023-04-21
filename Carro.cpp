#include "Carro.h"
#include <string>

Carro CriarCarroRandom(LinhasFicheiro& marca, LinhasFicheiro& modelo) {
	Carro novo_carro = Carro();
	novo_carro.marca = marca.linhas[rand() % marca.tamanho];
	novo_carro.modelo = modelo.linhas[rand() % modelo.tamanho];
	novo_carro.ID = 0;
	novo_carro.tempo_reparacao_max = 2 + (rand() % 3);
	novo_carro.dias_em_reparacao = 0;
	novo_carro.prioritario = false;

	return novo_carro;
}
/*Fazer probalidades--rand() vai retornar um valor entre 0 e rand_max*/
/*https://stackoverflow.com/questions/20309009/get-true-or-false-with-a-given-probability*/

bool  GerarProbalidades(double probalidade) {
	bool probalidade_final =  rand() < (probalidade * (RAND_MAX + 1.0));
	return probalidade_final;
}


Carro CriarCarro(LinhasFicheiro &marcas, LinhasFicheiro &modelos) {
	Carro novo_carro = Carro();
	novo_carro.marca = marcas.linhas[rand() % marcas.tamanho];
	novo_carro.modelo = modelos.linhas[rand() % modelos.tamanho];
	novo_carro.ID = 0;
	novo_carro.tempo_reparacao_max = 2 + (rand() % 3);
	novo_carro.dias_em_reparacao = 0;

	/*Por alguma razao prioritario apenas retorna 0 e 1 sendo falso e verdadeiro,respetivamente*/

	novo_carro.prioritario = GerarProbalidades(0.05);

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
	tamanho = tamanho_novo;
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
	tamanho = tamanho_novo;

}

void Transfere(Carro*& v_origem, int& tamanho_origem, int& indice, Carro*& v_dest, int& tamanho_dest)
{
	Carro carro = v_origem[indice];
	Adiciona(v_dest, tamanho_dest, carro);
	Remove(v_origem, tamanho_origem, indice);
}