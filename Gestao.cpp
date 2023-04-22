#include <iostream>
#include "gestao.h"
#include "Mecanico.h"
#include <fstream>;

using namespace std;

void MenuInfo(Oficina& Of,LinhasFicheiro& marcas,LinhasFicheiro& modelos){
/* Fazer um for para aparecer as informacoes na consola(ainda falta algumas informações) */
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
			<< "Prioritario: " << Of.fila_espera[i].prioritario << " | " << "Tempo de reparacao maximo: " << Of.fila_espera[i].tempo_reparacao_max << endl;
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
	
	case 2:
		atualizar_tempo_reparacao(Of);
		MenuInfo(Of, marcas, modelos);
		Menu(Of, marcas, modelos);
		break;
			
	case 3:
		adicionar_prioridade(Of);
		MenuInfo(Of, marcas, modelos);
		Menu(Of, marcas, modelos);
		break;

	case 4:
		remover_mecanico(Of, marcas);
		MenuInfo(Of, marcas, modelos);
		Menu(Of, marcas, modelos);
		break;

	case 5:
		gravar_oficina(Of);
		MenuInfo(Of, marcas, modelos);
		Menu(Of, marcas, modelos);
		break;
	case 6:
		carregar_oficina(Of);
		MenuInfo(Of, marcas, modelos);
		Menu(Of, marcas, modelos);
		break;
	/*case 7:

	case 8:
	}*/
	}
}

void reparacao_manual(Oficina& Of) {
	
	string marca;
	string modelo;
	cout << "indique a marca a reparar: " << endl;
	
	//ws tira os espaços em branco
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

void atualizar_tempo_reparacao(Oficina& Of) {
	string marca;
	string modelo;
	cout << "indique a marca a reparar: " << endl;
	cin >> ws;
	getline(cin, marca);
	cout << "indique o modelo a reparar: " << endl;
	cin >> ws;
	getline(cin, modelo);
	for (int i = 0; i < Of.fila_espera_tamanho;i++) {
		if ((Of.fila_espera[i].marca == marca) && (Of.fila_espera[i].modelo == modelo)) {
			Of.fila_espera[i].tempo_reparacao_max = 10; // foi colcado a dez de tempo max
		}
	}
}
void adicionar_prioridade(Oficina& Of) {
	int Id;
	cout << "indique O ID do carro que quer por a Prioritario: " << endl;
	cin >> Id;
	for (int i = 0; i < Of.fila_espera_tamanho;i++) {
		//faz se id for igual e se n for prioritario
		if ((Of.fila_espera[i].ID == Id) && (Of.fila_espera[i].prioritario==false)) {
			Of.fila_espera[i].prioritario = true;
		}
	}
	
}

void remover_mecanico(Oficina& Of, LinhasFicheiro& marcas) {
	string mecanicoRem;
	string mecanicoAdi;
	cout << "Indique o nome do mecanico que deseja remover: " << endl;
	cin >> ws;
	getline(cin, mecanicoRem);
	for (int i = 0; i < Of.numero_ets;i++) {
		if (Of.ets[i].mecanico.nome == mecanicoRem) {
			

			//repara todos os carros da et
			for (int j = Of.ets[i].num_carros_a_ser_reparados - 1; j >= 0;j--) {


				//coloca carro em lista de carros reparados
				Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados] = Of.ets[i].carros_a_ser_reparados[j];
				Of.ets[i].num_carros_reparados = Of.ets[i].num_carros_reparados + 1;
				Of.ets[i].faturacao = Of.ets[i].faturacao + (Of.ets[i].carros_a_ser_reparados[j].dias_em_reparacao * Of.ets[i].mecanico.preco_reparacao_por_dia);

				//remove carro da lista de carros em reparacao
				Remove(Of.ets[i].carros_a_ser_reparados, Of.ets[i].num_carros_a_ser_reparados, j);
			
			}
			Of.ets[i].mecanico = Mecanico();

			//adicionar novo mecanico
			cout << "O mecanico com o nome " << mecanicoRem << ", foi removido da et" << endl;
			cout << "ET: " << Of.ets[i].ID << " | " << "Mecanico: " << Of.ets[i].mecanico.nome
				<< " | " << "Capacidade: " << Of.ets[i].capacidade << " | " << "Carros: " << Of.ets[i].num_carros_a_ser_reparados << " | " <<
				"Marca: " << Of.ets[i].mecanico.marca << " | " << "Total Faturacao: " << Of.ets[i].faturacao << endl;
			cout << endl;
			cout << "Indique o nome para o novo mecanico desta et: " << endl;
			getline(cin, mecanicoAdi);
			Mecanico novo = Mecanico();

			novo.marca = marcas.linhas[rand() % marcas.tamanho];
			novo.preco_reparacao_por_dia = float(rand() % 300 + 90);
			novo.nome = mecanicoAdi;
			Of.ets[i].mecanico = novo;
			cout << "O mecanico com o nome " << Of.ets[i].mecanico.nome << ", foi adicionado na et" << endl;
			cout << "ET: " << Of.ets[i].ID << " | " << "Mecanico: " << Of.ets[i].mecanico.nome
				<< " | " << "Capacidade: " << Of.ets[i].capacidade << " | " << "Carros: " << Of.ets[i].num_carros_a_ser_reparados << " | " <<
				"Marca: " << Of.ets[i].mecanico.marca << " | " << "Total Faturacao: " << Of.ets[i].faturacao << endl;
			cout << "--------------------------------------------------------------------------------------" << endl;
		}
	}
}
void gravar_oficina(Oficina& Of) {

	string caminho = "oficina.txt";

	// cria um objeto ofstream
	ofstream ficheiro;

	// abre o ficheiro
	ficheiro.open(caminho);

	// verifica se o ficheiro foi aberto com sucesso
	if (ficheiro.is_open()) {
	/*	ficheiro << "ciclos:" << Of.ciclos  << endl;
		ficheiro << "carrostotais:" << Of.carrostotais << endl;
		ficheiro << "numero_ets:" << Of.numero_ets << endl;
		ficheiro << "ets" << endl;
		for (int i = 0; i < Of.numero_ets;i++) {
			ficheiro << "ID:" << Of.ets[i].ID << endl;
			ficheiro << "capacidade:" << Of.ets[i].capacidade << endl;
			ficheiro << "faturacao:" << Of.ets[i].faturacao << endl;
			ficheiro << "numero_carros:" << Of.ets[i].numero_carros << endl;
			ficheiro << "num_carros_a_ser_reparados:" << Of.ets[i].num_carros_a_ser_reparados << endl;
			ficheiro << "num_carros_reparados:" << Of.ets[i].num_carros_reparados << endl;
			ficheiro << "Carrosreparados" << endl;
			for (int j = 0; j < Of.ets[i].num_carros_reparados; j++) {
				
				ficheiro << "ID:" << Of.ets[i].Carrosreparados[j].ID << endl;
				ficheiro << "dias_em_reparacao:" << Of.ets[i].Carrosreparados[j].dias_em_reparacao << endl;
				ficheiro << "marca:" << Of.ets[i].Carrosreparados[j].marca << endl;
				ficheiro << "modelo:" << Of.ets[i].Carrosreparados[j].modelo << endl;
				ficheiro << "prioritario:" << Of.ets[i].Carrosreparados[j].prioritario << endl;
				ficheiro << "tempo_reparacao_max:" << Of.ets[i].Carrosreparados[j].tempo_reparacao_max << endl;
			}
			ficheiro << "CarrosreparadosFim" << endl;
			ficheiro << "carros_a_ser_reparados";
			for (int k = 0; k < Of.ets[i].num_carros_a_ser_reparados;k++) {
				ficheiro << "carros_a_ser_reparados:" << Of.ets[i].carros_a_ser_reparados[k].dias_em_reparacao << endl;
				ficheiro << "ID:" << Of.ets[i].carros_a_ser_reparados[k].ID << endl;
				ficheiro << "marca:" << Of.ets[i].carros_a_ser_reparados[k].marca << endl;
				ficheiro << "modelo:" << Of.ets[i].carros_a_ser_reparados[k].modelo << endl;
				ficheiro << "prioritario:" << Of.ets[i].carros_a_ser_reparados[k].prioritario << endl;
				ficheiro << "tempo_reparacao_max:" << Of.ets[i].carros_a_ser_reparados[k].tempo_reparacao_max << endl;
			}
			ficheiro << "carros_a_ser_reparados_Fim" << endl;
			ficheiro << "mecanico" << endl;
			ficheiro << "marca:" << Of.ets[i].mecanico.marca << endl;;
			ficheiro << "nome:" << Of.ets[i].mecanico.nome << endl;
			ficheiro << "preco_reparacao_por_dia:" << Of.ets[i].mecanico.preco_reparacao_por_dia << endl;
			ficheiro << "mecanicoFim" << endl;
		}
		ficheiro << "etsFim" << endl;
		ficheiro << "fila_espera" << endl;
		for (int y = 0; y < Of.fila_espera_tamanho; y++) {
			ficheiro << "ID:" << Of.fila_espera[y].ID << endl;
			ficheiro << "dias_em_reparacao:" << Of.fila_espera[y].dias_em_reparacao << endl;
			ficheiro << "marca:" << Of.fila_espera[y].marca << endl;;
			ficheiro << "modelo:" << Of.fila_espera[y].modelo << endl;
			ficheiro << "prioritario:" << Of.fila_espera[y].prioritario << endl;
			ficheiro << "tempo_reparacao_max:" << Of.fila_espera[y].tempo_reparacao_max << endl;
		}
		ficheiro << "fila_espera_Fim" << endl;
		ficheiro << "fila_espera_tamanho:" << Of.fila_espera_tamanho << endl;*/

		ficheiro << Of.ciclos << endl;
		ficheiro << Of.carrostotais << endl;
		ficheiro << Of.numero_ets << endl;
		//ets
		for (int i = 0; i < Of.numero_ets;i++) {
			ficheiro << Of.ets[i].ID << endl;
			ficheiro << Of.ets[i].capacidade << endl;
			ficheiro << Of.ets[i].faturacao << endl;
			ficheiro << Of.ets[i].numero_carros << endl;
			ficheiro << Of.ets[i].num_carros_a_ser_reparados << endl;
			//carros reparados
			ficheiro << Of.ets[i].num_carros_reparados << endl;
			for (int j = 0; j < Of.ets[i].num_carros_reparados; j++) {

				ficheiro << Of.ets[i].Carrosreparados[j].ID << endl;
				ficheiro << Of.ets[i].Carrosreparados[j].dias_em_reparacao << endl;
				ficheiro << Of.ets[i].Carrosreparados[j].marca << endl;
				ficheiro << Of.ets[i].Carrosreparados[j].modelo << endl;
				ficheiro << Of.ets[i].Carrosreparados[j].prioritario << endl;
				ficheiro << Of.ets[i].Carrosreparados[j].tempo_reparacao_max << endl;
			}
			//carros a ser reparados
			for (int k = 0; k < Of.ets[i].num_carros_a_ser_reparados;k++) {
				ficheiro << Of.ets[i].carros_a_ser_reparados[k].dias_em_reparacao << endl;
				ficheiro << Of.ets[i].carros_a_ser_reparados[k].ID << endl;
				ficheiro << Of.ets[i].carros_a_ser_reparados[k].marca << endl;
				ficheiro << Of.ets[i].carros_a_ser_reparados[k].modelo << endl;
				ficheiro << Of.ets[i].carros_a_ser_reparados[k].prioritario << endl;
				ficheiro << Of.ets[i].carros_a_ser_reparados[k].tempo_reparacao_max << endl;
			}
			//mecanico
			ficheiro << Of.ets[i].mecanico.marca << endl;
			ficheiro << Of.ets[i].mecanico.nome << endl;
			ficheiro << Of.ets[i].mecanico.preco_reparacao_por_dia << endl;
		}
		//fila de espera
		ficheiro << Of.fila_espera_tamanho << endl;
		for (int y = 0; y < Of.fila_espera_tamanho; y++) {
			ficheiro << Of.fila_espera[y].ID << endl;
			ficheiro << Of.fila_espera[y].dias_em_reparacao << endl;
			ficheiro << Of.fila_espera[y].marca << endl;
			ficheiro << Of.fila_espera[y].modelo << endl;
			ficheiro << Of.fila_espera[y].prioritario << endl;
			ficheiro << Of.fila_espera[y].tempo_reparacao_max << endl;
		}


		// fecha o arquivo
		ficheiro.close();
	}
	else {
		cout << "Erro ao abrir o ficheiro" << endl;
	}

}
void carregar_oficina(Oficina& Of) {
	string caminho = "oficina.txt";
	ifstream ficheiro(caminho);
	if (ficheiro.is_open()) {

		Oficina nova;
		ficheiro >> nova.ciclos;
		ficheiro >> nova.carrostotais;
		ficheiro >> nova.numero_ets;
		nova.ets = new EstacaoTrabalho[nova.numero_ets];
		//carrega ets
		for (int i = 0; i < nova.numero_ets; i++) {
			ficheiro >> nova.ets[i].ID;
			ficheiro >> nova.ets[i].capacidade;
			ficheiro >> nova.ets[i].faturacao;
			ficheiro >> nova.ets[i].numero_carros;
			ficheiro >> nova.ets[i].num_carros_a_ser_reparados;
			//carros reparados
			ficheiro >> nova.ets[i].num_carros_reparados;
			nova.ets[i].Carrosreparados = new Carro[nova.ets[i].num_carros_reparados];
			for (int j = 0; j < nova.ets[i].num_carros_reparados; j++) {

				ficheiro >> nova.ets[i].Carrosreparados[j].ID;
				ficheiro >> nova.ets[i].Carrosreparados[j].dias_em_reparacao;
				ficheiro >> nova.ets[i].Carrosreparados[j].marca;
				ficheiro >> nova.ets[i].Carrosreparados[j].modelo;
				ficheiro >> nova.ets[i].Carrosreparados[j].prioritario;
				ficheiro >> nova.ets[i].Carrosreparados[j].tempo_reparacao_max;
			}
			//carros a ser reparados
			nova.ets[i].carros_a_ser_reparados = new Carro[nova.ets[i].num_carros_a_ser_reparados];
			for (int k = 0; k < nova.ets[i].num_carros_a_ser_reparados; k++) {
				ficheiro >> nova.ets[i].carros_a_ser_reparados[k].dias_em_reparacao;
				ficheiro >> nova.ets[i].carros_a_ser_reparados[k].ID;
				ficheiro >> nova.ets[i].carros_a_ser_reparados[k].marca;
				ficheiro >> nova.ets[i].carros_a_ser_reparados[k].modelo;
				ficheiro >> nova.ets[i].carros_a_ser_reparados[k].prioritario;
				ficheiro >> nova.ets[i].carros_a_ser_reparados[k].tempo_reparacao_max;
			}
			//mecanico
			nova.ets[i].mecanico = Mecanico();
			ficheiro >> nova.ets[i].mecanico.marca;
			ficheiro >> nova.ets[i].mecanico.nome;
			ficheiro >> nova.ets[i].mecanico.preco_reparacao_por_dia;
		}
		//carrega fila de espera
		ficheiro >> nova.fila_espera_tamanho;
		nova.fila_espera = new Carro[nova.fila_espera_tamanho];
		for (int y = 0; y < nova.fila_espera_tamanho; y++) {
			ficheiro >> nova.fila_espera[y].ID;
			ficheiro >> nova.fila_espera[y].dias_em_reparacao;
			ficheiro >> nova.fila_espera[y].marca;
			ficheiro >> nova.fila_espera[y].modelo;
			ficheiro >> nova.fila_espera[y].prioritario;
			ficheiro >> nova.fila_espera[y].tempo_reparacao_max;
		}
		ficheiro.close();

		//liberta memoria
		delete[] Of.fila_espera;
		for (int i = 0; i < Of.numero_ets; i++) {
			delete[] Of.ets[i].Carrosreparados;
			delete[] Of.ets[i].carros_a_ser_reparados;
		}
		delete[] Of.ets;
		//delete &Of;
		//atribui a nova oficina
		Of = nova;

	}
	else {
		cout << "Erro: Ficheiro não encontrado!!";
	}


}
//Este carregamento deverá também ser possível ao passar o caminho do(s)ficheiro(s) por argumento na
//execução do programa.
void carregar_oficina2(int argc, char* argv[]) {

}
void imprimir_oficina(Oficina& Of) {

}