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
	while ((preco > 100) || (preco <= 0)) {
		cout << "Introduza um preco por dia do mecanico valido (inteiro entre 0 e 100)" << endl;
		getline(cin,entrada);
		while (!verificarnumero(entrada)) {
			cout << "Entrada invalida!" << endl << "Introduza o preco por dia do mecanico (inteiro entre 0 e 100)" << endl;
			getline(cin,entrada);
		}
	preco = stoi(entrada);
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
