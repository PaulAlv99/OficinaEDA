#pragma once
#include "Ficheiros.h"
struct Mecanico {
	std::string nome;
	std::string marca;
	float preco_reparacao_por_dia;
};

Mecanico CriarMecanico(LinhasFicheiro marcas);
