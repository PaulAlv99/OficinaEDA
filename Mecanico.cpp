#include "Mecanico.h"

Mecanico CriarMecanico(LinhasFicheiro& marcas)
{
	Mecanico novo = Mecanico();
	string entrada;
	int preco = 0;
	novo.marca = marcas.linhas[rand() % marcas.tamanho];
	cout << "Introduza o nome do mecanico " << endl;
	cin >> ws;
	getline(cin,novo.nome);
	cout << "Introduza o preco por dia do mecanico (inteiro entre 0 e 100)" << endl;
	cin >> entrada;
	while (!verificarnumero(entrada)) {
		cout << "Entrada invalida!" << endl << "Introduza o preco por dia do mecanico (inteiro entre 0 e 100)" << endl;
		cin >> entrada;
	}
	preco = stoi(entrada);
	while ((preco > 100) || (preco <= 0)) {
		cout << "Entrada invalida!" << endl << "Introduza o preco por dia do mecanico (inteiro entre 0 e 100) " << endl;
		cin >> preco;
	}
	novo.preco_reparacao_por_dia = preco;
	return novo;
}


bool verificarnumero(string n) {
	for (int i = 0; i < n.length(); i++) {
		if (isdigit(n[i]) == false) {
			return false;
		}
	}
	return true;
}
