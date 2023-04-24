#include <iostream>
#include "gestao.h"
#include "Mecanico.h"
#include <fstream>
#include <sstream>
#include <string>

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
					if ((Of.ciclos >= 1) && (Of.ets[i].carros_a_ser_reparados[t].ID != 0)) {
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
					cout << Of.ets[i].Carrosreparados[t].tempo_reparacao_max << "| Custo de reparacao: " << Of.ets[i].Carrosreparados[t].custoreparacao << endl;
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
	bool sair = false;
	do {
		cout << "Dia (s)eguinte *********** (g)estao" << endl << "(T)erminar programa" << endl;

		cout << "Seleccione a sua opcao : " << endl;
		cin >> escolha;
		switch (escolha) {
		case 's':
		case 'S':
			seguinte(Of, marcas, modelos);
			MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;
		case 'g':
		case 'G':
			gestao(Of, marcas, modelos);
			sair = true;
			break;
		case 't':
		case 'T':
			sair = true;
			break;

		default:
			cout << "Opcao invalida" << endl;
			break;

		}
	} while (!sair);

}
void gestao(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
	int opcao;
	int escolha = 0;
	int escolha2 = 0;
	string caminho = "oficina.txt";
	bool sair = false;
	do {
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
			system("CLS");

			MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;

		case 2:
			atualizar_tempo_reparacao(Of);
			system("CLS");
			MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;

		case 3:
			adicionar_prioridade(Of);
			system("CLS");
			MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;

		case 4:
			remover_mecanico(Of, marcas);
			system("CLS");
			MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;

		case 5:
			gravar_oficina(Of);
			system("CLS");
			MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;
		case 7:

			cout << "Escolha como quer imprimir a Oficina" << endl << "(1) Alfabeticamente" << endl << "(2) Por dias em reparacao" << endl;
			cin >> escolha;
			if (escolha == 1) {
				system("CLS");
				imprimir_oficinaalfabeticamente(Of);
			}
			else if (escolha == 2) {
				system("CLS");
				imprimir_oficinaportempo(Of);
			}
			else {
				cout << "Opcao invalida" << endl;
			}
			//MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;
		case 8:
			Menu(Of, marcas, modelos);
			sair = true;

			break;
		case 6:
			cout << "Digite: " << endl << "(1) Escolher o caminho manualmente" << endl << "(2) Usar o caminho padrao (Oficina.txt)" << endl;
			cin >> escolha2;
			switch (escolha2) {

			case 1:
				cout << "Digite o caminho (inclua .txt ao fim do nome do arquivo): " << endl;
				cin >> caminho;
				break;
			case 2:
				break;
			default:
				cout << "Opcao invalida" << endl << "Imprimindo usando o caminho padrao..." << endl;
				break;
			}

			carregar_oficina(Of, caminho);
			system("CLS");
			MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;

		default:
			cout << "Opcao invalida" << endl;
			break;
		}
	} while (!sair);
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
	/*Percorre ETs*/
	for (int i = 0; i < Of.numero_ets;i++) {
		
		/*Percorre carros a serem reparados*/
		for (int j = 0; j < Of.ets[i].capacidade; j++) {
			/*Se alguma das marcas corresponder � marca e modelo em questao*/
			if ((Of.ets[i].carros_a_ser_reparados[j].marca == marca) && (Of.ets[i].carros_a_ser_reparados[j].modelo == modelo) && (Of.ets[i].carros_a_ser_reparados[j].ID != 0)) {
				
				//coloca carro em lista de carros reparados
				Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados] = Of.ets[i].carros_a_ser_reparados[j];
				Of.ets[i].num_carros_reparados = Of.ets[i].num_carros_reparados + 1;
				Of.ets[i].faturacao = Of.ets[i].faturacao + (Of.ets[i].carros_a_ser_reparados[j].dias_em_reparacao * Of.ets[i].mecanico.preco_reparacao_por_dia);

				//remove carro da lista de carros em reparacao
				Of.ets[i].carros_a_ser_reparados[j].ID = 0;
				Of.ets[i].num_carros_a_ser_reparados = Of.ets[i].num_carros_a_ser_reparados - 1;

			}
		}
		
	}

}

void atualizar_tempo_reparacao(Oficina& Of) {
	
	string marca;
	string modelo;
	int tempo;
	cout << "indique a marca a atualizar o tempo de reparacao: " << endl;
	cin >> ws;
	getline(cin, marca);
	cout << "indique o modelo a atualizar o tempo de reparacao: " << endl;
	cin >> ws;
	getline(cin, modelo);
	for (int i = 0; i < Of.fila_espera_tamanho;i++) {
		if ((Of.fila_espera[i].marca == marca) && (Of.fila_espera[i].modelo == modelo)) {
			cout << "Introduza o respetivo tempo: \n ";
			cin >> tempo;
			Of.fila_espera[i].tempo_reparacao_max = tempo;
														
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
	colocarprioritario(Of);
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
			for (int j = 0; j < Of.ets[i].capacidade; j++) {

				if (Of.ets[i].carros_a_ser_reparados[j].ID != 0) {
					//coloca carro em lista de carros reparados
					Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados] = Of.ets[i].carros_a_ser_reparados[j];
					Of.ets[i].num_carros_reparados = Of.ets[i].num_carros_reparados + 1;
					Of.ets[i].faturacao = Of.ets[i].faturacao + (Of.ets[i].carros_a_ser_reparados[j].dias_em_reparacao * Of.ets[i].mecanico.preco_reparacao_por_dia);

					//remove carro da lista de carros em reparacao
					Of.ets[i].carros_a_ser_reparados[j].ID = 0;
					Of.ets[i].num_carros_a_ser_reparados = Of.ets[i].num_carros_a_ser_reparados - 1;

				}
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

		ficheiro << Of.ciclos << "|" 
		<< Of.carrostotais << "|" 
		<< Of.numero_ets << "\n";
		//ets
		for (int i = 0; i < Of.numero_ets;i++) {
			ficheiro << Of.ets[i].ID << "|"	
			<< Of.ets[i].capacidade << "|" 
			<< Of.ets[i].faturacao << "|"
			
			<< Of.ets[i].num_carros_a_ser_reparados << "|" 
			<< Of.ets[i].num_carros_reparados << "\n";
			for (int j = 0; j < Of.ets[i].num_carros_reparados; j++) {
				ficheiro << Of.ets[i].Carrosreparados[j].ID << "|" 
				<< Of.ets[i].Carrosreparados[j].dias_em_reparacao << "|"
				<< Of.ets[i].Carrosreparados[j].marca << "|" 
				<< Of.ets[i].Carrosreparados[j].modelo << "|" 
				<< Of.ets[i].Carrosreparados[j].prioritario << "|"
				<< Of.ets[i].Carrosreparados[j].custoreparacao << "|"
				<< Of.ets[i].Carrosreparados[j].tempo_reparacao_max << "\n";
			}
			//carros a ser reparados
			for (int k = 0; k < Of.ets[i].capacidade;k++) {
				ficheiro << Of.ets[i].carros_a_ser_reparados[k].dias_em_reparacao << "|" 
				<< Of.ets[i].carros_a_ser_reparados[k].ID << "|"
				<< Of.ets[i].carros_a_ser_reparados[k].marca << "|" 
				<< Of.ets[i].carros_a_ser_reparados[k].modelo << "|" 
				<< Of.ets[i].carros_a_ser_reparados[k].prioritario << "|" 
				<< Of.ets[i].carros_a_ser_reparados[k].tempo_reparacao_max <<"\n";
			}
			//mecanico
			ficheiro << Of.ets[i].mecanico.marca << "|" 
			<< Of.ets[i].mecanico.nome << "|" 
			<< Of.ets[i].mecanico.preco_reparacao_por_dia << "\n";
		}
		//fila de espera
		ficheiro << Of.fila_espera_tamanho << "\n";
		for (int y = 0; y < Of.fila_espera_tamanho; y++) {
			ficheiro << Of.fila_espera[y].ID << "|" 
			<< Of.fila_espera[y].dias_em_reparacao << "|"
			<< Of.fila_espera[y].marca << "|" 
			<< Of.fila_espera[y].modelo << "|"
			<< Of.fila_espera[y].prioritario << "|" 
			<< Of.fila_espera[y].tempo_reparacao_max << "\n";
		}


		// fecha o arquivo
		ficheiro.close();
	}
	else {
		cout << "Erro ao abrir o ficheiro" << endl;
	}

}



void carregar_oficina(Oficina& Of, string caminho) {
	//string caminho = "oficina.txt";
	

	ifstream ficheiro(caminho);

	if (ficheiro.is_open()) {

		Oficina nova = Oficina();
		string linha;
		
		getline(ficheiro, linha);
			
		stringstream ss(linha);
		string temp;

		//obtem ciclos
		getline(ss, temp, '|');
		nova.ciclos = stoi(temp);

		//obtem carrostotais
		getline(ss, temp, '|');
		nova.carrostotais = stoi(temp);

		//obtem numero_ets
		getline(ss, temp, '|');
		nova.numero_ets = stoi(temp);
		//cria as ets
		nova.ets = new EstacaoTrabalho[nova.numero_ets];
		
		for (int i = 0; i < nova.numero_ets;i++) {
			
			getline(ficheiro, linha);
			stringstream ss(linha);

			//obtem ID
			getline(ss, temp, '|');
			nova.ets[i].ID = stoi(temp);
			//obtem capacidade
			getline(ss, temp, '|');
			nova.ets[i].capacidade = stoi(temp);
			//faturacao
			getline(ss, temp, '|');
			nova.ets[i].faturacao = stof(temp);
			
			//num carros a ser reparados
			getline(ss, temp, '|');
			nova.ets[i].num_carros_a_ser_reparados = stoi(temp);
			//carros reparados
			getline(ss, temp, '|');
			nova.ets[i].num_carros_reparados = stoi(temp);
			nova.ets[i].Carrosreparados = new Carro[nova.ets[i].num_carros_reparados];
			if (nova.ets[i].num_carros_reparados > 0) {
			
				for (int j = 0; j < nova.ets[i].num_carros_reparados; j++) {
					getline(ficheiro, linha);
					stringstream ss(linha);
					//obtem o id do carro reparado
					getline(ss, temp, '|');
					nova.ets[i].Carrosreparados[j].ID = stoi(temp);
					//obtem o numero de dias de reparacao
					getline(ss, temp, '|');
					nova.ets[i].Carrosreparados[j].dias_em_reparacao = stoi(temp);
					//obtem a marca
					getline(ss, temp, '|');
					nova.ets[i].Carrosreparados[j].marca = temp;
					//obtem o modelo
					getline(ss, temp, '|');
					nova.ets[i].Carrosreparados[j].modelo = temp;
					//obtem prioritario
					getline(ss, temp, '|');
					nova.ets[i].Carrosreparados[j].prioritario = stoi(temp);
					//obtem custo de reparacao
					getline(ss, temp, '|');
					nova.ets[i].Carrosreparados[j].custoreparacao = stoi(temp);
					//obtem tempo de reparacao maximo
					getline(ss, temp, '|');
					nova.ets[i].Carrosreparados[j].tempo_reparacao_max = stoi(temp);

				}
			}
			//carros a ser reparados
			nova.ets[i].carros_a_ser_reparados = new Carro[nova.ets[i].capacidade];
			if (nova.ets[i].capacidade > 0) {
			
				for (int k = 0; k < nova.ets[i].capacidade; k++) {
					getline(ficheiro, linha);
					stringstream ss(linha);
					//obtem dias em reparacao
					getline(ss, temp, '|');
					nova.ets[i].carros_a_ser_reparados[k].dias_em_reparacao = stoi(temp);
					//obtem id do carro em peracao
					getline(ss, temp, '|');
					nova.ets[i].carros_a_ser_reparados[k].ID = stoi(temp);
					//obtem marca
					getline(ss, temp, '|');
					nova.ets[i].carros_a_ser_reparados[k].marca = temp;
					//obtem modelo
					getline(ss, temp, '|');
					nova.ets[i].carros_a_ser_reparados[k].modelo = temp;
					//obtem prioridade
					getline(ss, temp, '|');
					nova.ets[i].carros_a_ser_reparados[k].prioritario = stoi(temp);
					//obtem tempo de reparacao maximo
					getline(ss, temp, '|');
					nova.ets[i].carros_a_ser_reparados[k].tempo_reparacao_max = stoi(temp);

				}
			}
			getline(ficheiro, linha);
			stringstream ss1(linha);
			//mecanico
			nova.ets[i].mecanico = Mecanico();
			//obtem marca
			getline(ss1, temp, '|');
			nova.ets[i].mecanico.marca = temp;
			//obtem nome do mecanico
			getline(ss1, temp, '|');
			nova.ets[i].mecanico.nome = temp;
			//obtem pre�o de reparacao por dia
			getline(ss1, temp, '|');
			nova.ets[i].mecanico.preco_reparacao_por_dia = stof(temp);

		}
		getline(ficheiro, linha);
		stringstream ss2(linha);
		//carrega fila de espera
		getline(ss2, temp, '|');
		nova.fila_espera_tamanho = stoi(temp);
		nova.fila_espera = new Carro[nova.fila_espera_tamanho];
		for (int y = 0; y < nova.fila_espera_tamanho; y++) {
			getline(ficheiro, linha);
			stringstream ss3(linha);
			//obtem id do carro em espera
			getline(ss3, temp, '|');
			nova.fila_espera[y].ID = stoi(temp);
			//obtem dias em reparacao do carro em espera
			getline(ss3, temp, '|');
			nova.fila_espera[y].dias_em_reparacao = stoi(temp);
			//obtem marca do carro
			getline(ss3, temp, '|');
			nova.fila_espera[y].marca = temp;
			//obtem modelo do carro
			getline(ss3, temp, '|');
			nova.fila_espera[y].modelo = temp;
			//obtem prioridade do carro em espera
			getline(ss3, temp, '|');
			nova.fila_espera[y].prioritario = stoi(temp);
			//obtem tempo de reparacao maximo do carro em espera
			getline(ss3, temp, '|');
			nova.fila_espera[y].tempo_reparacao_max = stoi(temp);
		}
		ficheiro.close();

		//liberta memoria
		delete[] Of.fila_espera;
		for (int i = 0; i < Of.numero_ets; i++) {
			delete[] Of.ets[i].Carrosreparados;
			delete[] Of.ets[i].carros_a_ser_reparados;
		}
		delete[] Of.ets;
		//atribui a nova oficina
		Of = nova;


	}
	else {
		cout << "Erro: Ficheiro n�o encontrado!!" << endl << "usando valores locais" << endl;
	}

}



void imprimir_oficinaalfabeticamente(Oficina& Of) {
	int num_carros_total = 0;
	for (int i = 0; i < Of.numero_ets; i++) {
		num_carros_total += Of.ets[i].num_carros_a_ser_reparados + Of.ets[i].num_carros_reparados;
	}
	num_carros_total += Of.fila_espera_tamanho;
	Carro* carros_total = new Carro[num_carros_total]; // aloca mem�ria para o array de carros

	// Copia os carros de todas as ETs e da fila de espera para o array carros_total
	int k = 0;
	for (int i = 0; i < Of.numero_ets; i++) {
		for (int j = 0; j < Of.ets[i].num_carros_a_ser_reparados; j++) {
			carros_total[k] = Of.ets[i].carros_a_ser_reparados[j];
			k++;
		}
		for (int r = 0; r < Of.ets[i].num_carros_reparados; r++) {
			carros_total[k] = Of.ets[i].Carrosreparados[r];
			k++;
		}
	}
	for (int i = 0; i < Of.fila_espera_tamanho; i++) {
		carros_total[k] = Of.fila_espera[i];
		k++;
	}

	// Ordena o array de carros alfabeticamente e por dias_reparacao
	OrdenarCarrosAlfabeticamenteEPorDiasReparacao(carros_total, num_carros_total);


}

void imprimir_oficinaportempo(Oficina& Of) {
	int num_carros_total = 0;
	for (int i = 0; i < Of.numero_ets; i++) {
		num_carros_total += Of.ets[i].num_carros_a_ser_reparados + Of.ets[i].num_carros_reparados;
	}
	num_carros_total += Of.fila_espera_tamanho;
	Carro* carros_total = new Carro[num_carros_total]; // aloca mem�ria para o array de carros

	// Copia os carros de todas as ETs e da fila de espera para o array carros_total
	int k = 0;
	for (int i = 0; i < Of.numero_ets; i++) {
		for (int j = 0; j < Of.ets[i].num_carros_a_ser_reparados; j++) {
			carros_total[k] = Of.ets[i].carros_a_ser_reparados[j];
			k++;
		}
		for (int r = 0; r < Of.ets[i].num_carros_reparados; r++) {
			carros_total[k] = Of.ets[i].Carrosreparados[r];
			k++;
		}
	}
	for (int i = 0; i < Of.fila_espera_tamanho; i++) {
		carros_total[k] = Of.fila_espera[i];
		k++;
	}

	// Ordena o array de carros alfabeticamente e por dias_reparacao
	OrdenarCarrosPorDiasReparacao(carros_total, num_carros_total);


}
void OrdenarCarrosAlfabeticamenteEPorDiasReparacao(Carro*& carros, int num_carros) {

	// Ordenar o array de "carros" alfabeticamente e por dias_em_reparacao
	for (int i = 0; i < num_carros - 1; i++) {
		for (int j = i + 1; j < num_carros; j++) {
			if (carros[i].marca > carros[j].marca ||
				(carros[i].marca == carros[j].marca && carros[i].modelo > carros[j].modelo) ||
				(carros[i].marca == carros[j].marca && carros[i].modelo == carros[j].modelo && carros[i].dias_em_reparacao > carros[j].dias_em_reparacao) ||
				(carros[i].marca == carros[j].marca && carros[i].modelo == carros[j].modelo && carros[i].dias_em_reparacao == carros[j].dias_em_reparacao && carros[i].prioritario < carros[j].prioritario)) {
				Carro temp = carros[i];
				carros[i] = carros[j];
				carros[j] = temp;
			}
		}
	}

	for (int k = 0; k < num_carros; k++)
	{
		cout << "ID: " << carros[k].ID << " | Marca: " << carros[k].marca << " | Modelo: " << carros[k].modelo << " | Tempo: " << carros[k].dias_em_reparacao << " | Prioritario: " << carros[k].prioritario << endl;
	}
}

void OrdenarCarrosPorDiasReparacao(Carro*& carros, int num_carros) {

	// Ordenar o array de "carros" alfabeticamente e por dias_em_reparacao
	for (int i = 0; i < num_carros - 1; i++) {
		for (int j = i + 1; j < num_carros; j++) {
			if (carros[i].dias_em_reparacao > carros[j].dias_em_reparacao) {
				Carro temp = carros[i];
				carros[i] = carros[j];
				carros[j] = temp;
			}
		}
	}

	for (int k = 0; k < num_carros; k++)
	{
		cout << "ID: " << carros[k].ID << " | Marca: " << carros[k].marca << " | Modelo: " << carros[k].modelo << " | Tempo: " << carros[k].dias_em_reparacao << " | Prioritario: " << carros[k].prioritario << endl;
	}
}
