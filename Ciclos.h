#pragma once
#include "ET.h"
#include "Oficina.h"
#include "Carro.h"
#include <string>

void reparacao(EstacaoTrabalho ID1, Oficina METAL, Carro ID2);

void criacao10carros(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);