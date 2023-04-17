#include <iostream>
#include "gestao.h"

using namespace std;

void MenuInfo(int numero_ets, EstacaoTrabalho* ET, Oficina METAL){
/* Fazer um for para aparecer as informacoes na consola(ainda falta algumas informações) */
for (int i = 0; i < numero_ets; i++) {
	cout << "ET: " << ET[i].ID << " | " << "Mecanico: " << METAL.ets[i].mecanico.nome
		<< " | " << "Capacidade: " << METAL.ets[i].capacidade << " | " << "Carros: " << METAL.ets[i].numero_carros << " | " <<
		"Marca: " << METAL.ets[i].mecanico.marca << " | " << "Total Faturacao: "
		<< METAL.ets[i].faturacao << " | " << "Dia: " << METAL.ciclos << endl;
}
cout << "--------------------------------------------------------------------------------------" << endl;
cout << "Lista de Espera: " << endl;
for (int i = 0; i < 10; i++) {
	cout << "ID: " << METAL.fila_espera[i].ID << " | " << "Modelo: " << METAL.fila_espera[i].modelo << " | " << "Marca: " << METAL.fila_espera[i].marca << " | "
		<< "Prioritario: " << METAL.fila_espera[i].prioritario << endl;
}
}

void Menu(int numero_ets, EstacaoTrabalho* ET, Oficina METAL) {
	char escolha;
	cout << "Dia (s)eguinte *********** (g)estao" << endl;
	cout << "Seleccione a sua opcao : " << endl;
	cin >> escolha;
	switch (escolha) {
	case 's':
		METAL.ciclos++;
		
		MenuInfo(numero_ets, ET, METAL);
		Menu(numero_ets, ET, METAL);
		break;
	case 'g':
		gestao();
		break;
	case (not 'g') and (not 's'):
		Menu(numero_ets, ET, METAL);
			break;

	}

}
void gestao() {
	int opcao;
	cout << " ***** Bem Vindo Gestor *****" << endl;
	cout << "(1).Reparacao Manual" << endl;
	cout << "(2).Atualizar tempo de reparacao" << endl;
	cout << "(3).Adicionar Prioridade" << endl;
	cout << "(4).Remover Mecanico" << endl;
	cout << "(5).Gravar Oficina" << endl;
	cout << "(6).Carregar Oficina" << endl;
	cout << "(7).Imprimir Oficina" << endl;
	cout << "(8).Sair da gestao" << endl;
	cout << "Seleccione a sua opcao : ";
	cin >> opcao;
	/*switch (opcao) {
	case 1:

	case 2:

	case 3:

	case 4:

	case 5:

	case 6:

	case 7:

	case 8:
	}*/
}

void reparacao_manual() {
}

void atualizar_tempo_reparacao() {

}
void adicionar_prioridade() {

}

void remover_mecanico() {

}
void gravar_oficina() {

}
void carregar_oficina() {

}
void imprimir_oficina() {

}