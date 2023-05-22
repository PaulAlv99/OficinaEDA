#include <iostream>
#include "gestao.h"
#include "Mecanico.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Arvore.h"

using namespace std;

void MenuInfo(Oficina& Of,LinhasFicheiro& marcas,LinhasFicheiro& modelos){
	cout << "Dia: " << Of.ciclos << endl;
	EstacaoTrabalho* atualET = Of.ets;
	
	
	listacarros* atualespera = &Of.listaespera;
	while (atualET != NULL) {
			cout << "ET: " << Of.ets->ID << " | " << "Mecanico: " << Of.ets->mecanico.nome
				<< " | " << "Capacidade: " << Of.ets->capacidade << " | " << "Carros: " << Of.ets->num_carros_a_ser_reparados << " | " <<
				"Marca: " << Of.ets->mecanico.marca << " | " << "Total Faturacao: " << Of.ets->faturacao << endl;
			if (Of.ciclos >= 1) {
				cout << "Carros a ser reparados: " << endl;
			}
			int r = Of.ets->capacidade;
			if(Of.ets->num_carros_a_ser_reparados>0){
				listacarros* atualcarrosaserreparados = atualET->carros_a_ser_reparados;
				while (atualcarrosaserreparados != NULL) {
					if ((Of.ciclos >= 1) && (atualcarrosaserreparados->carro.ID != 0)) {
						cout << "ID: " << atualcarrosaserreparados->carro.ID << " | " << "Carro: " << atualcarrosaserreparados->carro.marca << "-"
							<< atualcarrosaserreparados->carro.modelo << " | " << "Prioritario: ";
						if (atualcarrosaserreparados->carro.prioritario == 1) {
							cout << "Sim";
						}
						else {
							cout << "Nao";
						}
						cout << " | " << "Tempo de reparacao: " << atualcarrosaserreparados->carro.dias_em_reparacao << " | " << "Tempo de reparacao maximo: ";
						cout << atualcarrosaserreparados->carro.tempo_reparacao_max << endl;
					}
					atualcarrosaserreparados = atualcarrosaserreparados->seguinte;
				}
				atualcarrosaserreparados = atualcarrosaserreparados->inicio;
		}
			cout << endl;



		if (Of.ciclos >= 1) {
				cout << "Carros reparados: " << endl;
			}
			//O Paulo e que sabe como fez a arvore
			/*Arvore* atualcarrosreparados = atualET->Carrosreparados;
			while (atualcarrosreparados != NULL) {
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
			cout << endl;*/


			atualET = atualET->seguinte;
	}
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << "Lista de Espera: " << endl;
	while (atualespera != NULL) {
		cout << "ID: " << atualespera->carro.ID << " | " << "Modelo: " << atualespera->carro.modelo << " | " << "Marca: " << atualespera->carro.marca << " | "
			<< "Prioritario: ";
		if (atualespera->carro.prioritario == 1) {
			cout << "Sim";
		}
		else {
			cout << "Nao";
		}
		cout<< " | " << "Tempo de reparacao maximo: " << atualespera->carro.tempo_reparacao_max << endl;
		atualespera = atualespera->seguinte;
	}
	atualespera = atualespera->inicio;

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
	//A partir daqui e copiar a funcao reparar
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
	//percorrer lista de espera
	listacarros* atual = &Of.listaespera;
	while  (atual != NULL) {
		if (removerespacos((maiuscula(atual->carro.marca))) == removerespacos(maiuscula(marca)) && (removerespacos(maiuscula(atual->carro.modelo)) == removerespacos(maiuscula(modelo)))) {
			atual->carro.tempo_reparacao_max = tempo;
														
		}
		atual = atual->seguinte;
	}
	atual = atual->inicio;
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
	//percorrer lista de espera
	listacarros* atual = &Of.listaespera;
	while (atual != NULL) {
		//faz se id for igual e se n for prioritario
		if ((atual->carro.ID == Id) && (atual->carro.prioritario==false)) {
			atual->carro.prioritario = true;
		}
		atual = atual->seguinte;
	}
	organizarprioritario(Of);
}

void remover_mecanico(Oficina& Of, LinhasFicheiro& marcas) {
	string mecanicoRem;
	string mecanicoAdi;
	cout << "Indique o nome do mecanico que deseja remover: " << endl;
	cin >> ws;
	getline(cin, mecanicoRem);
	EstacaoTrabalho* atualET = Of.ets;
	while (atualET != NULL) {
		if (removerespacos(maiuscula(atualET->mecanico.nome)) == removerespacos(maiuscula(mecanicoRem))) {
			

			//repara todos os carros da et
			listacarros* atualcarrosaserreparados = atualET->carros_a_ser_reparados;
			while (atualcarrosaserreparados !=NULL) {

				if (atualcarrosaserreparados->carro.ID != 0) {
					//coloca carro em lista de carros reparados
					// adicionar numa arvore
					//Adiciona(Of.ets[i].Carrosreparados, tamanho, Of.ets[i].carros_a_ser_reparados[j]);
					atualET->num_carros_a_ser_reparados = atualET->num_carros_a_ser_reparados - 1;
					atualcarrosaserreparados->carro.ID = 0;
					atualET->faturacao = atualET->faturacao + (atualcarrosaserreparados->carro.dias_em_reparacao * atualET->mecanico.preco_reparacao_por_dia);
					//Adicionar o custo de reparacao deste ultimo carro reparado
					//Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados].custoreparacao = Of.ets[i].mecanico.preco_reparacao_por_dia * Of.ets[i].Carrosreparados[Of.ets[i].num_carros_reparados].dias_em_reparacao;
					atualET->num_carros_reparados = atualET->num_carros_reparados + 1;
				}
				atualcarrosaserreparados = atualcarrosaserreparados->seguinte;
			}
			atualcarrosaserreparados = atualcarrosaserreparados->seguinte;

			//adicionar novo mecanico
			cout << "O mecanico com o nome " << mecanicoRem << ", foi removido da et" << endl;
			cout << "ET: " << atualET->ID << " | " << "Mecanico: " << atualET->mecanico.nome
				<< " | " << "Capacidade: " << atualET->capacidade << " | " <<
				"Marca: " << atualET->mecanico.marca << " | " << "Total Faturacao: " << atualET->faturacao << endl;
			cout << endl;
			Mecanico* novo = CriarMecanico(marcas);
			
			//remover a ET antiga e criar uma nova ou algo semelhante
			EstacaoTrabalho* temp = &CriarET(atualET->ID);
			atualET->ID = temp->ID;
			atualET->capacidade = temp->capacidade;
			atualET->Carrosreparados = temp->Carrosreparados;
			atualET->carros_a_ser_reparados = temp->carros_a_ser_reparados;
			atualET->faturacao = temp->faturacao;
			atualET->mecanico = temp->mecanico;
			atualET->num_carros_a_ser_reparados = temp->num_carros_a_ser_reparados;
			atualET->num_carros_reparados = temp->num_carros_reparados;
			/*
			Of.ets[i] = CriarET(Of.ets[i].ID);
			Of.ets[i].mecanico = novo;*/
		}
		atualET = atualET->seguinte;
	}
	atualET = atualET->inicio;
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
            listacarros* atualReparados = et.Carrosreparados;
            while (atualReparados != nullptr) {
                Carro& carro = atualReparados->carro;
                ficheiro << carro.ID << "|" 
                         << carro.dias_em_reparacao << "|"
                         << carro.marca << "|" 
                         << carro.modelo << "|" 
                         << carro.prioritario << "|"
                         << carro.custoreparacao << "|"
                         << carro.tempo_reparacao_max << "\n";
                atualReparados = atualReparados->seguinte;
            }

            // Gravação dos carros na fila de espera
            listacarros* atualEspera = et.carros_a_ser_reparados;
            while (atualEspera != nullptr) {
                Carro& carro = atualEspera->carro;
                ficheiro << carro.dias_em_reparacao << "|" 
                         << carro.ID << "|"
                         << carro.marca << "|" 
                         << carro.modelo << "|" 
                         << carro.prioritario << "|" 
                         << carro.tempo_reparacao_max <<"\n";
                atualEspera = atualEspera->seguinte;
            }

            // Gravação dos dados do mecânico
            Mecanico& mecanico = et.mecanico;
            ficheiro << mecanico.marca << "|" 
                     << mecanico.nome << "|" 
                     << mecanico.preco_reparacao_por_dia << "\n";
        }

        // Gravação dos dados da fila de espera
        ficheiro << Of.fila_espera_tamanho << "\n";
        listacarros* atualFilaEspera = &Of.listaespera;
        while (atualFilaEspera != nullptr) {
            Carro& carro = atualFilaEspera->carro;
            ficheiro << carro.ID << "|" 
                     << carro.dias_em_reparacao << "|"
                     << carro.marca << "|" 
                     << carro.modelo << "|"
                     << carro.prioritario << "|" 
                     << carro.tempo_reparacao_max << "\n";
            atualFilaEspera = atualFilaEspera->seguinte;
        }

        ficheiro.close();
    } else {
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
			//obtem preço de reparacao por dia
			getline(ss1, temp, '|');
			nova.ets[i].mecanico.preco_reparacao_por_dia = stoi(temp);

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
		cout << "Erro: Ficheiro não encontrado!!" << endl << "usando valores locais" << endl;
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

