#include "Mecanico.h"

Mecanico CriarMecanico(LinhasFicheiro& marcas)
{
	Mecanico novo = Mecanico();
	int preco = 0;
	novo.marca = marcas.linhas[rand() % marcas.tamanho];
	cout << "Introduza o nome do mecanico " << endl;
	cin >> ws;
	getline(cin,novo.nome);

	while ((preco > 100) || (preco <= 0)) {
		cout << "Introduza o preco por dia do mecanico (inteiro entre 0 e 100) " << endl;
		cin >> preco;
	}
	novo.preco_reparacao_por_dia = preco;
	return novo;
}
