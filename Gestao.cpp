#include <iostream>
#include "gestao.h"

using namespace std;

void MenuInfo(Oficina& Of,LinhasFicheiro& marcas,LinhasFicheiro& modelos){
/* Fazer um for para aparecer as informacoes na consola(ainda falta algumas informa��es) */
	cout << "Dia: " << Of.ciclos << endl;
	for (int i = 0; i < Of.numero_ets; i++) {
			cout << "ET: " << Of.ets[i].ID << " | " << "Mecanico: " << Of.ets[i].mecanico.nome
				<< " | " << "Capacidade: " << Of.ets[i].capacidade << " | " << "Carros: " << Of.ets[i].num_carros_a_ser_reparados << " | " <<
				"Marca: " << Of.ets[i].mecanico.marca << " | " << "Total Faturacao: " << Of.ets[i].faturacao << endl;
			if (Of.ciclos >= 1) {
				cout << "Carros a ser reparados: " << endl;
			}
			int r = Of.ets[i].capacidade;
			if(Of.ets[i].num_carros_a_ser_reparados>0){
				for (int t = 0; t < r; t++) {
					if ((Of.ciclos >= 1) && (Of.ets[i].carros_a_ser_reparados[t].ID > 0)) {
						cout << "ID: " << Of.ets[i].carros_a_ser_reparados[t].ID << " | " << "Carro: " << Of.ets[i].carros_a_ser_reparados[t].marca << "-"
							<< Of.ets[i].carros_a_ser_reparados[t].modelo << " | " << "Prioritario: " << Of.ets[i].carros_a_ser_reparados[t].prioritario;
						cout << " | " << "Tempo de reparacao: " << Of.ets[i].carros_a_ser_reparados[t].dias_em_reparacao << " | " << "Tempo de reparacao maximo: ";
						cout << Of.ets[i].carros_a_ser_reparados[t].tempo_reparacao_max << endl;
					}
				}
		}
			cout << endl;



		if (Of.ciclos >= 1) {
				cout << "Carros reparados: " << endl;
			}
			int g = Of.ets[i].num_carros_reparados;
			for (int t = 0; t < g; t++) {
				if ((Of.ciclos >= 1) && (Of.ets[i].Carrosreparados[t].ID != 0)) {
					cout << "ID: " << Of.ets[i].Carrosreparados[t].ID << " | " << "Carro: " << Of.ets[i].Carrosreparados[t].marca << "-"
						<< Of.ets[i].Carrosreparados[t].modelo << " | " << "Prioritario: " << Of.ets[i].Carrosreparados[t].prioritario;
					cout << " | " << "Tempo de reparacao: " << Of.ets[i].Carrosreparados[t].dias_em_reparacao << " | " << "Tempo de reparacao maximo: ";
					cout << Of.ets[i].Carrosreparados[t].tempo_reparacao_max << endl;
				}

			}
			cout << endl;



	}
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << "Lista de Espera: " << endl;
	for (int i = 0; i < Of.fila_espera_tamanho; i++) {
		cout << "ID: " << Of.fila_espera[i].ID << " | " << "Modelo: " << Of.fila_espera[i].modelo << " | " << "Marca: " << Of.fila_espera[i].marca << " | "
			<< "Prioritario: " << Of.fila_espera[i].prioritario << endl;
	}
}

void Menu(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
	char escolha;
	cout << "Dia (s)eguinte *********** (g)estao" << endl;
	cout << "Seleccione a sua opcao : " << endl;
	cin >> escolha;
	switch (escolha) {
	case 's':
		seguinte(Of,marcas,modelos);
		MenuInfo(Of,marcas,modelos);
		Menu(Of,marcas,modelos);
		break;
	case 'g':
		gestao(Of, marcas, modelos);
		break;
	case (not 'g') and (not 's'):
		Menu(Of,marcas,modelos);
			break;

	}

}
void gestao(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
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
	switch (opcao) {
	case 1:
		reparacao_manual(Of);
		MenuInfo(Of, marcas, modelos);
		Menu(Of, marcas, modelos);
		break;
		/*case 2:

	case 3:

	case 4:

	case 5:

	case 6:

	case 7:

	case 8:
	}*/
	}
}

void reparacao_manual(Oficina& Of) {
	
	string marca;
	string modelo;
	cout << "indique a marca a reparar: " << endl;
	
	//ws tira os espa�os em branco
	cin >> ws;
	getline(cin, marca);
	cout << "indique o modelo a reparar: " << endl;
	cin >> ws;
	getline(cin, modelo);
	
	for (int i = 0; i < Of.numero_ets;i++) {
		for (int j = Of.ets[i].num_carros_a_ser_reparados-1; j >= 0;j--){
			if ((Of.ets[i].carros_a_ser_reparados[j].marca == marca) && (Of.ets[i].carros_a_ser_reparados[j].modelo == modelo)) {
				
				//coloca carro em lista de carros reparados
				Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados] = Of.ets[i].carros_a_ser_reparados[j];
				Of.ets[i].num_carros_reparados = Of.ets[i].num_carros_reparados + 1;
				Of.ets[i].faturacao = Of.ets[i].faturacao + (Of.ets[i].carros_a_ser_reparados[j].dias_em_reparacao * Of.ets[i].mecanico.preco_reparacao_por_dia);

				//remove carro da lista de carros em reparacao
				Remove(Of.ets[i].carros_a_ser_reparados, Of.ets[i].num_carros_a_ser_reparados, j);

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
void adicionar_prioridade(Oficina& Of) {

}

void remover_mecanico(Oficina& Of) {

}
void gravar_oficina(Oficina& Of) {

}
void carregar_oficina(LinhasFicheiro& Nome_Ficheiro) {

}
//Este carregamento dever� tamb�m ser poss�vel ao passar o caminho do(s)ficheiro(s) por argumento na
//execu��o do programa.
void carregar_oficina2(int argc, char* argv[]) {

}
void imprimir_oficina(Oficina& Of) {

}