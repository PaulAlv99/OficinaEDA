#pragma once
#include <iostream>
#include "Oficina.h"
#include "Ciclos.h"

void MenuInfo(Oficina& METAL,LinhasFicheiro& marcas,LinhasFicheiro& modelos);
void Menu(Oficina& METAL, LinhasFicheiro& marcas, LinhasFicheiro& modelos);

void gestao();
void reparacao_manual();
void atualizar_tempo_reparacao();
void adicionar_prioridade();
void remover_mecanico();
void gravar_oficina();
void carregar_oficina();
void imprimir_oficina();
