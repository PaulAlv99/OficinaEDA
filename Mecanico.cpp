#include "Mecanico.h"

Mecanico CriarMecanico(LinhasFicheiro& marcas)
{
	Mecanico novo = Mecanico();

	novo.marca = marcas.linhas[rand() % marcas.tamanho];
	novo.preco_reparacao_por_dia = float(rand() % 300 + 90);
	cout << "Introduza o nome do mecanico " << endl;
	getline(cin,novo.nome);
	return novo;
}
