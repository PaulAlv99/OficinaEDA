#pragma once
#include "Ficheiros.h"

/*struct Mecanico {
	string nome = "";
	string marca = "";
	int preco_reparacao_por_dia = 0;
};

Mecanico CriarMecanico(LinhasFicheiro& marcas);
bool verificarnumero(string n);

*/


struct Mecanico {
    string nome = {};
    string marca = {};
    int preco_reparacao_por_dia = 0;
    Mecanico* proximo = NULL;
};


Mecanico* CriarMecanico(LinhasFicheiro& marcas);
bool VerificarNumero(const string& n);

Mecanico* AdicionarMecanico(Mecanico* lista, Mecanico* novoMecanico);
void LiberarLista(Mecanico* lista);