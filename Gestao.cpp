#include <iostream>
#include "gestao.h"
#include "Mecanico.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void MenuInfo(Oficina& Of,LinhasFicheiro& marcas,LinhasFicheiro& modelos){
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
							<< Of.ets[i].carros_a_ser_reparados[t].modelo << " | " << "Prioritario: "; 
						if (Of.ets[i].carros_a_ser_reparados[t].prioritario == 1) {
							cout << "Sim";
						}
						else {
							cout << "Nao";
						}
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
						<< Of.ets[i].Carrosreparados[t].modelo << " | " << "Prioritario: ";
					if (Of.ets[i].Carrosreparados[t].prioritario == 1) {
						cout << "Sim";
					}
					else {
						cout << "Nao";
					}
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
			<< "Prioritario: ";
		if (Of.fila_espera[i].prioritario == 1) {
			cout << "Sim";
		}
		else {
			cout << "Nao";
		}
		cout<< " | " << "Tempo de reparacao maximo: " << Of.fila_espera[i].tempo_reparacao_max << endl;
	}
}

void Menu(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
	string escolha;
	bool sair = false;
	do {
		cout << "Dia (s)eguinte *********** (g)estao" << endl << "(T)erminar programa" << endl;

		cout << "Seleccione a sua opcao : " << endl;
		getline(cin, escolha);
		while (escolha.length() != 1) {
			cout << "Escolha invalida! Digite apenas uma das letras destacadas abaixo." << endl;
			cout << "Dia (s)eguinte *********** (g)estao" << endl << "(T)erminar programa" << endl;

			cout << "Seleccione a sua opcao : " << endl;
			getline(cin, escolha);
			cout << endl;
		}

		switch (escolha[0]) {
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
	string escolha1temp;
	double escolha1temporaria = 0;
	int escolha = 0;
	string escolha2temp;
	double escolha2temporaria = 0;
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
		case 6:

			while ((escolha2temporaria > 2) || (escolha2temporaria <= 0)) {
				cout << "Digite: " << endl << "(1) Escolher o caminho manualmente" << endl << "(2) Usar o caminho padrao (Oficina.txt)" << endl;
				cin >> ws;
				getline(cin, escolha2temp);
				while (!verificarnumero(escolha2temp)) {
					cout << "Opcao invalida! Tente novamente" << endl;;
					cout << "Digite: " << endl << "(1) Escolher o caminho manualmente" << endl << "(2) Usar o caminho padrao (Oficina.txt)" << endl;
					getline(cin, escolha2temp);
				}
				escolha2temporaria = stod(escolha2temp);
				if ((escolha2temporaria > 2) || (escolha2temporaria <= 0)) {
					escolha2temporaria = 0;
				}
				else {
					escolha2 = escolha2temporaria;
				}
			}
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

		case 7:

			
			while ((escolha1temporaria > 2) || (escolha1temporaria <= 0)) {
				cout << "Escolha como quer imprimir a Oficina" << endl << "(1) Alfabeticamente" << endl << "(2) Por dias em reparacao" << endl;
				cin >> ws;
				getline(cin, escolha1temp);
				while (!verificarnumero(escolha1temp)) {
					cout << "Opcao invalida! Tente novamente" << endl;;
					cout << "Escolha como quer imprimir a Oficina" << endl << "(1) Alfabeticamente" << endl << "(2) Por dias em reparacao" << endl;
					getline(cin, escolha1temp);
				}
				escolha1temporaria = stod(escolha1temp);
				if ((escolha1temporaria > 2) || (escolha1temporaria <= 0)) {
					escolha1temporaria = 0;
				}
				else {
					escolha = escolha1temporaria;
				}
			}
			escolha = (int)escolha1temporaria;
			if (escolha == 1) {
				system("CLS");
				cout << "Lista ordenada alfabeticamente: " << endl;
				imprimir_oficinaalfabeticamente(Of);
				cout << endl;
			}
			else if (escolha == 2) {
				system("CLS");
				cout << "Lista ordenada por tempo de reparacao: " << endl;
				imprimir_oficinaportempo(Of);
				cout << endl;
			}
			else {
				cout << "Opcao invalida" << endl;
			}
			MenuInfo(Of, marcas, modelos);
			Menu(Of, marcas, modelos);
			sair = true;
			break;
		case 8:
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

	//ws tira os espaços em branco
	cin >> ws;
	getline(cin, marca);
	cout << "indique o modelo a reparar: " << endl;
	cin >> ws;
	getline(cin, modelo);
	/*Percorre ETs*/
	for (int i = 0; i < Of.numero_ets; i++) {

		/*Percorre carros a serem reparados*/
		for (int j = 0; j < Of.ets[i].capacidade; j++) {
			/*Se alguma das marcas corresponder à marca e modelo em questao*/
			if (removerespacos(maiuscula((Of.ets[i].carros_a_ser_reparados[j].marca))) == removerespacos(maiuscula(marca)) 
				&& (removerespacos(maiuscula(Of.ets[i].carros_a_ser_reparados[j].modelo)) == removerespacos(maiuscula(modelo)))
				&& (Of.ets[i].carros_a_ser_reparados[j].ID != 0) && (Of.ets[i].carros_a_ser_reparados[j].dias_em_reparacao >= 1)) {
				int tamanho = (Of.ets[i].num_carros_reparados);
				Adiciona(Of.ets[i].Carrosreparados, tamanho, Of.ets[i].carros_a_ser_reparados[j]);
				Of.ets[i].num_carros_a_ser_reparados = Of.ets[i].num_carros_a_ser_reparados - 1;
				Of.ets[i].carros_a_ser_reparados[j].ID = 0;
				Of.ets[i].faturacao = Of.ets[i].faturacao + (Of.ets[i].carros_a_ser_reparados[j].dias_em_reparacao * Of.ets[i].mecanico.preco_reparacao_por_dia);
				Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados].custoreparacao = Of.ets[i].mecanico.preco_reparacao_por_dia * Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados].dias_em_reparacao;
				Of.ets[i].num_carros_reparados = Of.ets[i].num_carros_reparados + 1;

			}
		}

	}

}

void atualizar_tempo_reparacao(Oficina& Of) {

	string marca;
	string modelo;
	string entrada;
	double tempotemp = 0;
	int tempo;
	cout << "indique a marca a atualizar o tempo de reparacao: " << endl;
	cin >> ws;
	getline(cin, marca);
	cout << "indique o modelo a atualizar o tempo de reparacao: " << endl;
	cin >> ws;
	getline(cin, modelo);
	cout << "Introduza o respetivo tempo: \n ";
	getline(cin, entrada);
	while ((tempotemp > 2147483647) || (tempotemp <= 0)) {
		while (!verificarnumero(entrada)) {
			cout << "Tempo invalido!" << endl << "introduza um tempo de reparacao valido (inteiro entre 0 e 2147483647): " << endl;
			getline(cin, entrada);
		}
		tempotemp = stod(entrada);
		if ((tempotemp <= 2147483647) &&( tempotemp > 0)){
			tempo = (int)tempotemp;

		}
		else {
			cout << "Tempo invalido!" << endl << "introduza um tempo de reparacao valido (inteiro entre 0 e 2147483647): " << endl;
			getline(cin, entrada);
			tempotemp = 0;
		}
	}

	for (int i = 0; i < Of.fila_espera_tamanho;i++) {
		if (removerespacos((maiuscula(Of.fila_espera[i].marca))) == removerespacos(maiuscula(marca)) && (removerespacos(maiuscula(Of.fila_espera[i].modelo)) == removerespacos(maiuscula(modelo)))) {
			Of.fila_espera[i].tempo_reparacao_max = tempo;
														
		}
	}
}
void adicionar_prioridade(Oficina& Of) {
	string entrada;
	double Idtemp = 0;
	int Id;
	cout << "indique O ID do carro que quer por a Prioritario: " << endl;
	cin >> ws;
	getline(cin, entrada);
	while ((Idtemp > 2147483647) || (Idtemp <= 0)) {
		while (!verificarnumero(entrada)) {
			cout << "ID invalido!" << endl << "Indique um ID valido para colocar como prioritario (inteiro): " << endl;
			getline(cin, entrada);
		}
		Idtemp = stod(entrada);
		if ((Idtemp <= 2147483647) && (Idtemp > 0)) {
			Id = (int)Idtemp;

		}
		else {
			cout << "ID invalido!" << endl << "Indique um ID valido para colocar como prioritario (inteiro entre 0 e 2147483647): " << endl;
			getline(cin, entrada);
			Idtemp = 0;
			}
	}
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
		if (removerespacos(maiuscula(Of.ets[i].mecanico.nome)) == removerespacos(maiuscula(mecanicoRem))) {
			

			//repara todos os carros da et
			for (int j = 0; j < Of.ets[i].capacidade; j++) {

				if (Of.ets[i].carros_a_ser_reparados[j].ID != 0) {
					//coloca carro em lista de carros reparados
					int tamanho = (Of.ets[i].num_carros_reparados);
					Adiciona(Of.ets[i].Carrosreparados, tamanho, Of.ets[i].carros_a_ser_reparados[j]);
					Of.ets[i].num_carros_a_ser_reparados = Of.ets[i].num_carros_a_ser_reparados - 1;
					Of.ets[i].carros_a_ser_reparados[j].ID = 0;
					Of.ets[i].faturacao = Of.ets[i].faturacao + (Of.ets[i].carros_a_ser_reparados[j].dias_em_reparacao * Of.ets[i].mecanico.preco_reparacao_por_dia);
					Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados].custoreparacao = Of.ets[i].mecanico.preco_reparacao_por_dia * Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados].dias_em_reparacao;
					Of.ets[i].num_carros_reparados = Of.ets[i].num_carros_reparados + 1;
				}
			}

			//adicionar novo mecanico
			cout << "O mecanico com o nome " << mecanicoRem << ", foi removido da et" << endl;
			cout << "ET: " << Of.ets[i].ID << " | " << "Mecanico: " << Of.ets[i].mecanico.nome
				<< " | " << "Capacidade: " << Of.ets[i].capacidade << " | " <<
				"Marca: " << Of.ets[i].mecanico.marca << " | " << "Total Faturacao: " << Of.ets[i].faturacao << endl;
			cout << endl;
			Mecanico novo = CriarMecanico(marcas);
			
			Of.ets[i] = CriarET(Of.ets[i].ID);
			Of.ets[i].mecanico = novo;
		}
	}
}
void gravar_oficina(Oficina& Of) {
    string caminho = "oficina.txt";
    ofstream ficheiro;
    ficheiro.open(caminho);

    if (ficheiro.is_open()) {
        // Gravação dos dados da oficina
        ficheiro << Of.ciclos << "|" 
                 << Of.carrostotais << "|" 
                 << Of.numero_ets << "\n";

        // Gravação dos dados de cada EstacaoTrabalho
        for (int i = 0; i < Of.numero_ets; i++) {
            EstacaoTrabalho& et = Of.ets[i];
            ficheiro << et.ID << "|" 
                     << et.capacidade << "|" 
                     << et.faturacao << "|"
                     << et.num_carros_a_ser_reparados << "|" 
                     << et.num_carros_reparados << "\n";

            // Gravação dos carros reparados
            no* atualReparados = et.Carrosreparados;
            while (atualReparados != nullptr) {
                Carro& carro = atualReparados->carro;
                ficheiro << carro.ID << "|" 
                         << carro.dias_em_reparacao << "|"
                         << carro.marca << "|" 
                         << carro.modelo << "|" 
                         << carro.prioritario << "|"
                         << carro.custoreparacao << "|"
                         << carro.tempo_reparacao_max << "\n";
                atualReparados = atualReparados->proximo;
            }

            // Gravação dos carros na fila de espera
            no* atualEspera = et.carros_a_ser_reparados;
            while (atualEspera != nullptr) {
                Carro& carro = atualEspera->carro;
                ficheiro << carro.dias_em_reparacao << "|" 
                         << carro.ID << "|"
                         << carro.marca << "|" 
                         << carro.modelo << "|" 
                         << carro.prioritario << "|" 
                         << carro.tempo_reparacao_max <<"\n";
                atualEspera = atualEspera->proximo;
            }

            // Gravação dos dados do mecânico
            Mecanico& mecanico = et.mecanico;
            ficheiro << mecanico.marca << "|" 
                     << mecanico.nome << "|" 
                     << mecanico.preco_reparacao_por_dia << "\n";
        }

        // Gravação dos dados da fila de espera
        ficheiro << Of.fila_espera_tamanho << "\n";
        no* atualFilaEspera = Of.fila_espera;
        while (atualFilaEspera != nullptr) {
            Carro& carro = atualFilaEspera->carro;
            ficheiro << carro.ID << "|" 
                     << carro.dias_em_reparacao << "|"
                     << carro.marca << "|" 
                     << carro.modelo << "|"
                     << carro.prioritario << "|" 
                     << carro.tempo_reparacao_max << "\n";
            atualFilaEspera = atualFilaEspera->proximo;
        }

        ficheiro.close();
    } else {
        cout << "Erro ao abrir o ficheiro" << endl;
    }
}




void carregar_oficina(Oficina& Of, const string& caminho) {
	ifstream ficheiro(caminho);

	if (ficheiro.is_open()) {
		Oficina nova;
		string linha;

		getline(ficheiro, linha);
		stringstream ss(linha);
		string temp;

		// Obtém ciclos
		getline(ss, temp, '|');
		nova.ciclos = stoi(temp);

		// Obtém carrostotais
		getline(ss, temp, '|');
		nova.carrostotais = stoi(temp);

		// Obtém numero_ets
		getline(ss, temp, '|');
		nova.numero_ets = stoi(temp);

		// Cria as ets
		nova.ets = new EstacaoTrabalho[nova.numero_ets];

		for (int i = 0; i < nova.numero_ets; i++) {
			getline(ficheiro, linha);
			stringstream ss(linha);

			// Obtém ID
			getline(ss, temp, '|');
			nova.ets[i].ID = stoi(temp);

			// Obtém capacidade
			getline(ss, temp, '|');
			nova.ets[i].capacidade = stoi(temp);

			// Obtém faturacao
			getline(ss, temp, '|');
			nova.ets[i].faturacao = stof(temp);

			// Obtém num carros a ser reparados
			getline(ss, temp, '|');
			nova.ets[i].num_carros_a_ser_reparados = stoi(temp);

			// Obtém carros reparados
			getline(ss, temp, '|');
			nova.ets[i].num_carros_reparados = stoi(temp);
			nova.ets[i].Carrosreparados = nullptr;

			if (nova.ets[i].num_carros_reparados > 0) {
				Carro* carros_reparados_head = nullptr;
				Carro* carros_reparados_tail = nullptr;

				for (int j = 0; j < nova.ets[i].num_carros_reparados; j++) {
					getline(ficheiro, linha);
					stringstream ss(linha);

					// Obtém o id do carro reparado
					getline(ss, temp, '|');
					int id = stoi(temp);

					// Obtém o numero de dias de reparacao
					getline(ss, temp, '|');
					int dias = stoi(temp);

					// Obtém a marca
					getline(ss, temp, '|');
					string marca = temp;

					// Obtém o modelo
					getline(ss, temp, '|');
					string modelo = temp;

					// Obtém prioritario
					getline(ss, temp, '|');
					int prioritario = stoi(temp);

					// Obtém custo de reparacao
					getline(ss, temp, '|');
					int custo_reparacao = stoi(temp);

					// Obtém tempo de reparacao maximo
					getline(ss, temp, '|');
					int tempo_reparacao_max = stoi(temp);

					Carro* carro = new Carro(id, dias, marca, modelo, prioritario, tempo_reparacao_max);

					if (carros_reparados_head == nullptr) {
						carros_reparados_head = carro;
						carros_reparados_tail = carro;
					}
					else {
						carros_reparados_tail->next = carro;
						carros_reparados_tail = carro;
					}
				}

				nova.ets[i].Carrosreparados = carros_reparados_head;
			}

			// Obtém carros a ser reparados
			getline(ss, temp, '|');
			nova.ets[i].carros_a_ser_reparados = nullptr;

			if (nova.ets[i].capacidade > 0) {
				Carro* carros_a_ser_reparados_head = nullptr;
				Carro* carros_a_ser_reparados_tail = nullptr;

				for (int k = 0; k < nova.ets[i].capacidade; k++) {
					getline(ficheiro, linha);
					stringstream ss(linha);

					// Obtém dias em reparacao
					getline(ss, temp, '|');
					int dias = stoi(temp);

					// Obtém id do carro em peracao
					getline(ss, temp, '|');
					int id = stoi(temp);

					// Obtém marca
					getline(ss, temp, '|');
					string marca = temp;

					// Obtém modelo
					getline(ss, temp, '|');
					string modelo = temp;

					// Obtém prioridade
					getline(ss, temp, '|');
					int prioritario = stoi(temp);

					// Obtém tempo de reparacao maximo
					getline(ss, temp, '|');
					int tempo_reparacao_max = stoi(temp);

					Carro* carro = new Carro(id, dias, marca, modelo, prioritario, tempo_reparacao_max);

					if (carros_a_ser_reparados_head == nullptr) {
						carros_a_ser_reparados_head = carro;
						carros_a_ser_reparados_tail = carro;
					}
					else {
						carros_a_ser_reparados_tail->next = carro;
						carros_a_ser_reparados_tail = carro;
					}
				}

				nova.ets[i].carros_a_ser_reparados = carros_a_ser_reparados_head;
			}

			getline(ficheiro, linha);
			stringstream ss1(linha);

			// Mecanico
			nova.ets[i].mecanico = Mecanico();

			// Obtém marca
			getline(ss1, temp, '|');
			nova.ets[i].mecanico.marca = temp;

			// Obtém nome do mecanico
			getline(ss1, temp, '|');
			nova.ets[i].mecanico.nome = temp;

			// Obtém preço de reparacao por dia
			getline(ss1, temp, '|');
			nova.ets[i].mecanico.preco_reparacao_por_dia = stoi(temp);
		}

		getline(ficheiro, linha);
		stringstream ss2(linha);

		// Carrega fila de espera
		getline(ss2, temp, '|');
		nova.fila_espera_tamanho = stoi(temp);
		nova.fila_espera = nullptr;

		if (nova.fila_espera_tamanho > 0) {
			Carro* fila_espera_head = nullptr;
			Carro* fila_espera_tail = nullptr;

			for (int y = 0; y < nova.fila_espera_tamanho; y++) {
				getline(ficheiro, linha);
				stringstream ss3(linha);

				// Obtém id do carro em espera
				getline(ss3, temp, '|');
				int id = stoi(temp);

				// Obtém dias em reparacao do carro em espera
				getline(ss3, temp, '|');
				int dias = stoi(temp);

				// Obtém marca do carro
				getline(ss3, temp, '|');
				string marca = temp;

				// Obtém modelo do carro
				getline(ss3, temp, '|');
				string modelo = temp;

				// Obtém prioridade do carro em espera
				getline(ss3, temp, '|');
				int prioritario = stoi(temp);

				// Obtém tempo de reparacao maximo do carro em espera
				getline(ss3, temp, '|');
				int tempo_reparacao_max = stoi(temp);

				Carro* carro = new Carro(id, dias, marca, modelo, prioritario, tempo_reparacao_max);

				if (fila_espera_head == nullptr) {
					fila_espera_head = carro;
					fila_espera_tail = carro;
				}
				else {
					fila_espera_tail->next = carro;
					fila_espera_tail = carro;
				}
			}

			nova.fila_espera = fila_espera_head;
		}

		ficheiro.close();

		// Liberta memoria
		delete[] Of.fila_espera;
		for (int i = 0; i < Of.numero_ets; i++) {
			Carro* carro_reparado = nova.ets[i].Carrosreparados;
			while (carro_reparado != nullptr) {
				Carro* next = carro_reparado->next;
				delete carro_reparado;
				carro_reparado = next;
			}

			Carro* carro_a_reparar = nova.ets[i].carros_a_ser_reparados;
			while (carro_a_reparar != nullptr) {
				Carro* next = carro_a_reparar->next;
				delete carro_a_reparar;
				carro_a_reparar = next;
			}
		}
		delete[] Of.ets;

		// Atribui a nova oficina
		Of = nova;
	}
	else {
		cout << "Erro: Ficheiro nao encontrado!!" << endl << "usando valores locais" << endl;
	}
}



void imprimir_oficinaalfabeticamente(Oficina& Of) {
	int num_carros_total = 0;
	for (int i = 0; i < Of.numero_ets; i++) {
		num_carros_total += Of.ets[i].num_carros_a_ser_reparados + Of.ets[i].num_carros_reparados;
	}
	num_carros_total += Of.fila_espera_tamanho;
	Carro* carros_total = new Carro[num_carros_total]; // aloca memória para o array de carros

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
	Carro* carros_total = new Carro[num_carros_total]; // aloca memória para o array de carros

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
		cout << "ID: " << carros[k].ID << " | Marca: " << carros[k].marca << " | Modelo: " << carros[k].modelo << " | Tempo: " << carros[k].dias_em_reparacao << " | Prioritario: ";
			if (carros[k].prioritario == 1) {
				cout << "Sim" << endl;
			}
			else {
				cout << "Nao" << endl;
			}
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
		cout << "ID: " << carros[k].ID << " | Marca: " << carros[k].marca << " | Modelo: " << carros[k].modelo << " | Tempo: " << carros[k].dias_em_reparacao << " | Prioritario: ";
			if (carros[k].prioritario == 1) {
				cout << "Sim" << endl;
			}
			else {
				cout << "Nao" << endl;
			}
	}
}

