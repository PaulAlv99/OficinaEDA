#include <iostream>
#include "gestao.h"

using namespace std;

void MenuInfo(Oficina& METAL,LinhasFicheiro& marcas,LinhasFicheiro& modelos){
/* Fazer um for para aparecer as informacoes na consola(ainda falta algumas informações) */
	cout << "Dia: " << METAL.ciclos << endl;
	for (int i = 0; i < METAL.numero_ets; i++) {
		cout << "ET: " << METAL.ets[i].ID << " | " << "Mecanico: " << METAL.ets[i].mecanico.nome
			<< " | " << "Capacidade: " << METAL.ets[i].capacidade << " | " << "Carros: " << METAL.ets[i].numero_carros << " | " <<
			"Marca: " << METAL.ets[i].mecanico.marca << " | " << "Total Faturacao: "
			<< METAL.ets[i].faturacao << endl;
	}
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << "Lista de Espera: " << endl;
	for (int i = 0; i < METAL.fila_espera_tamanho; i++) {
		cout << "ID: " << METAL.fila_espera[i].ID << " | " << "Modelo: " << METAL.fila_espera[i].modelo << " | " << "Marca: " << METAL.fila_espera[i].marca << " | "
			<< "Prioritario: " << METAL.fila_espera[i].prioritario << endl;
	}
}

void Menu(Oficina& METAL, LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
	char escolha;
	cout << "Dia (s)eguinte *********** (g)estao" << endl;
	cout << "Seleccione a sua opcao : " << endl;
	cin >> escolha;
	switch (escolha) {
	case 's':
		
		seguinte(METAL,marcas,modelos);
		MenuInfo(METAL,marcas,modelos);
		Menu(METAL,marcas,modelos);
		break;
	case 'g':
		gestao();
		break;
	case (not 'g') and (not 's'):
		Menu(METAL,marcas,modelos);
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

void reparacao_manual(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
	/*int CarroReparoManual(Oficina & Of, LinhasFicheiro & marcas, LinhasFicheiro & modelos);*/
	cout << "indique a marca e o modelo que pretende reparar manualmente: ";
	string marca;
	string modelo;
	cin >> marca;
	cin >> modelo;
	for (int i = 0; i <= Of.numero_ets;i++) {
		for (int j = 0; j <= Of.ets[i].numero_carros;j++){
			if (Of.ets[i].carros_a_ser_reparados[j].marca == marca && Of.ets[i].carros_a_ser_reparados[j].modelo == modelo) {
				// ir buscar funcao colocarCarrosEt no oficina.cpp
			}
		}
		
	}

}

void atualizar_tempo_reparacao(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
	cout << "indique a marca e o modelo que pretende reparar manualmente: ";
	string marca;
	string modelo;
	cin >> marca;
	cin >> modelo;
	for (int i = 0; i <= Of.fila_espera_tamanho;i++) {
		if (Of.fila_espera);
			
	}

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