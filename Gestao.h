#pragma once
#include <iostream>
#include "Oficina.h"

void MenuInfo(int numero_ets, EstacaoTrabalho* ET, Oficina METAL);
void Menu(int numero_ets, EstacaoTrabalho* ET,Oficina METAL);

void gestao();
void reparacao_manual();
void atualizar_tempo_reparacao();
void adicionar_prioridade();
void remover_mecanico();
void gravar_oficina();
void carregar_oficina();
void imprimir_oficina();
