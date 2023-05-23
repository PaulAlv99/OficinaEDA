#pragma once
#include "ET.h"

struct Oficina {
	EstacaoTrabalho ets;
	int numero_ets;
	listacarros listaespera;
	int fila_espera_tamanho;
	int carrostotais;
	int ciclos;

};

Oficina criarOficina(LinhasFicheiro &marcas, LinhasFicheiro &modelos);

void seguinte(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos);

void CriarCarrosNaFila(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos, int num);
bool  GerarProbalidades(double probalidade);
void ColocarCarrosET(Oficina& Of, int num);
void Transportar(Oficina& Of, int ind);

void colocarprioritario(Oficina& Of);
void ColocarCarrosET(Oficina& Of, int num);
void NovaListaEspera(listacarros & l);
void organizarprioritario(Oficina& Of);

/*
#include <iostream>
#include "Carro.h" // Inclui a definição da classe Carro


const int ERRO_LISTA_VAZIA = 1;
struct LEspera
{
	struct Elemento {
		Carro viatura;
		Elemento* seguinte;
	};
	Elemento* primeiro;
};

void NovaListaEspera(LEspera& l);

void InsereElementoListaEspera(LEspera& l, Carro c); // O parâmetro l é passado por referência para alterar o valor da lista de carros. Insere elemento no final da lista

void Remove(LEspera& l); // O parâmetro l é passado por referência para alterar o valor da lista de carros. Remove o primeiro elemento da lista
void InserePrioritario(LEspera& f, Carro c); // O parâmetro l é passado por referência para alterar o valor da lista de carros
int Comprimento(LEspera& l);
bool Vazia(LEspera& l);
Carro Primeiro(LEspera& l);
void Escreve(LEspera& l);

*/
