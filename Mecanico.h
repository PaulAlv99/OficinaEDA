#pragma once
#include "Ficheiros.h"
struct Mecanico {
	string nome;
	string marca;
	float preco_reparacao_por_dia;
};

Mecanico CriarMecanico(LinhasFicheiro marcas);
