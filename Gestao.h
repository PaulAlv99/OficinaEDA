#pragma once
#include <iostream>
#include "Oficina.h"
#include "Mecanico.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Arvore.h"
using namespace std;

void MenuInfo(Oficina& METAL,LinhasFicheiro& marcas,LinhasFicheiro& modelos);
void Menu(Oficina& METAL, LinhasFicheiro& marcas, LinhasFicheiro& modelos);

void gestao(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);
void reparacao_manual(Oficina& Of);
void atualizar_tempo_reparacao(Oficina& Of);
void adicionar_prioridade(Oficina& Of);
void remover_mecanico(Oficina& Of, LinhasFicheiro& marcas);
void gravar_oficina(Oficina& Of);
void carregar_oficina(Oficina& Of, const string& caminho);
void OrdenarCarrosAlfabeticamenteEPorDiasReparacao(Carro*& carros, int num_carros);
void OrdenarCarrosPorDiasReparacao(Carro*& carros, int num_carros);
void imprimir_oficinaportempo(Oficina& Of);
void imprimir_oficinaalfabeticamente(Oficina& Of);

//void imprimir_oficina_alfabeticamente()
//struct nodo {
//	int   dados;
//	nodo* esquerda;
//	nodo* direita;
//};
//void imprimeArvore(nodo* no, int nivel);
