#pragma once
#include <iostream>
#include "Oficina.h"
#include "Ciclos.h"

void MenuInfo(Oficina& METAL,LinhasFicheiro& marcas,LinhasFicheiro& modelos);
void Menu(Oficina& METAL, LinhasFicheiro& marcas, LinhasFicheiro& modelos);

void gestao(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);
void reparacao_manual(Oficina& Of);
void atualizar_tempo_reparacao(Oficina& Of);
void adicionar_prioridade(Oficina& Of);
void remover_mecanico(Oficina& Of, LinhasFicheiro& marcas);
void gravar_oficina();
void carregar_oficina();
void imprimir_oficina();
