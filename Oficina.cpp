#include "Oficina.h"


int numero_de_et() {
    int et_numero = 3 + (rand() % 5); // numero de ET por oficina random
    return et_numero;
}

Oficina criarOficina(LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
    Oficina nova = Oficina();
    nova.ciclos = 0; //dias de trabalho
    nova.numero_ets = numero_de_et();
	nova.ets = *CriarET(1);
	nova.ets.inicio = &nova.ets;
	nova.listaespera;
	nova.carrostotais = 0;
    nova.fila_espera_tamanho = 0;


    /* Criar os mecanicos conforme o numero de ets gerado*/
	
	nova.ets.mecanico = CriarMecanico(marcas);
	EstacaoTrabalho * atual = &nova.ets;
    for (int i = 1; i < nova.numero_ets - 1; i++) {
		atual->seguinte = CriarET(i + 1);
		atual->seguinte->inicio = atual->inicio;
		atual->seguinte->mecanico = CriarMecanico(marcas);
		atual = atual->seguinte;
    }
	atual->seguinte = NULL;
	atual->seguinte->inicio = atual->inicio;

    /*Criar 10 carros random*/
    CriarCarrosNaFila(nova,marcas,modelos,10);

	atual = atual->inicio;
    //Criar ET; criar os mecanicos; encher a fila ; criar os carros (lista das marcas e dos modelos);
    return nova;
}






bool MarcaPresente(Oficina &Of, string marca) {
	bool temp = false;
	EstacaoTrabalho * atual = &Of.ets;
	while(atual != NULL) {
		temp = (marca == atual->mecanico.marca);
		if (temp) {
			break;
		}
		atual = atual->seguinte;
	}

	return temp;
	atual = atual->inicio;
}


void CriarCarrosNaFila(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos, int num) {
	for (int i = 0; i < num; i) {
		Carro novo = CriarCarro(marcas, modelos);
		novo.ID = Of.carrostotais + 1;
		if (MarcaPresente(Of, novo.marca)) {
				adicionarcarro(Of.listaespera, novo);
				Of.carrostotais = Of.carrostotais + 1;
				i++;
		}
	}
	system("CLS");
}

//void ColocarCarrosET(Oficina& Of, int num) {
//	int colocados = 0;
//	while (colocados < num) {
//		for (int i = 0; i < Of.numero_ets; i++) {
//			for (int t = 0; t < Of.fila_espera_tamanho; t++) {
//				if ((Of.ets[i].mecanico.marca == Of.fila_espera[t].marca) && (Of.ets[i].capacidade > Of.ets[i].num_carros_a_ser_reparados) &&(colocados < num)) {
//					for (int z = 0; z < Of.ets[i].capacidade; z++) {
//						if (Of.ets[i].carros_a_ser_reparados[z].ID == 0) {
//							Of.ets[i].carros_a_ser_reparados[z] = Of.fila_espera[t];
//							colocados++;
//							Of.ets[i].num_carros_a_ser_reparados++;
//							Remove(Of.fila_espera, Of.fila_espera_tamanho, t);
//							break;
//						}
//					}
//
//					
//				}
//
//			}
//		}
//		break;
//	}
//}

void ColocarCarrosET(Oficina& Of, int num) {
	listacarros* atualespera = &Of.listaespera;
	EstacaoTrabalho* atualets = &Of.ets;
	
	int colocados = 0;
	while (colocados < num) {
		while (atualets != NULL) {
			while(atualespera!= NULL){
				if ((atualets->mecanico.marca == atualespera->carro.marca) && (atualets->capacidade > atualets->num_carros_a_ser_reparados) && (colocados < num)) {
					listacarros* atualcarrosaserreparados = atualets->carros_a_ser_reparados;
					while (atualcarrosaserreparados->seguinte != NULL) {
						if (atualcarrosaserreparados->carro.ID == 0) {
							atualcarrosaserreparados->carro = atualespera->carro;
							colocados++;
							atualets->num_carros_a_ser_reparados++;
							removecarro(*atualespera, atualespera->carro);
							break;
						}
						atualcarrosaserreparados = atualcarrosaserreparados->seguinte;
					}
					atualcarrosaserreparados = atualcarrosaserreparados->inicio;
				}
				atualespera = atualespera->seguinte;
			}
		}
		break;
	}
	atualespera = atualespera->inicio;
	atualets = atualets->inicio;
}

//void colocarprioritario(Oficina& Of) {
//	listacarros* atualespera = &Of.listaespera;
//	while (atualespera -> seguinte != NULL) {
//		if (atualespera->carro.prioritario) {
//			//Transportar(Of, i); mudar a funcao transportar
//		}
//		atualespera = atualespera->seguinte;
//	}
//}

//void Transportar(Oficina& Of, int ind) {
//	int tamanho = Of.fila_espera_tamanho;
//	int indice = 0;
//	for (int z = 0; z < ind; z++) {
//		if (Of.fila_espera[z].prioritario) {
//			indice = indice + 1;
//		}
//	}
//	Carro* novo = new Carro[tamanho];
//	novo[indice] = Of.fila_espera[ind];
//	for (int k = 0; k < indice; k++) {
//		novo[k] = Of.fila_espera[k];
//	}
//	for (int i = indice; i < ind; i++) {
//		novo[i + 1] = Of.fila_espera[i];
//	}
//	for (int j = ind + 1; j < tamanho; j++) {
//		novo[j] = Of.fila_espera[j];
//	}
//	
//	for (int i = 0; i < tamanho; i++) {
//		Of.fila_espera[i] = novo[i];
//	}
//	delete[] novo;
//}

//void Transportar(Oficina& Of, Carro &carro) {
//	listacarros* atualespera = &Of.listaespera;
//	listacarros* novo;
//	listacarros* temp;
//	bool colocado = false;
//	if (atualespera->inicio != NULL) {
//		novo->carro = atualespera->carro;
//		novo->seguinte = NULL;
//		novo->inicio = novo;
//	}
//	atualespera = atualespera->seguinte;
//	while(atualespera->seguinte!= NULL && atualespera->inicio != NULL && colocado == false){
//		if (atualespera->carro.prioritario) {
//			temp->carro = atualespera->carro;
//			temp->inicio = novo->inicio;
//			temp->seguinte = NULL;
//			novo->seguinte = temp;
//			atualespera = atualespera->seguinte;
//		}
//		else if (atualespera->carro.ID == carro.ID) {
//
//		}
//	}
//	delete[] novo;
//}

void organizarprioritario(Oficina& Of) {
	listacarros* atualespera = &Of.listaespera;
	listacarros* novo = &listacarros();
	listacarros* temp = & listacarros();
	listacarros* final = &listacarros();
	listacarros* finaltemp = &listacarros();
	while (atualespera->carro.prioritario != true && atualespera->inicio != NULL) {
		atualespera = atualespera->seguinte;
	}
	novo->carro = atualespera->carro;
	novo->seguinte = NULL;
	novo->inicio = novo;
	removecarro(*atualespera, atualespera->carro);
	while (atualespera != NULL && atualespera->inicio != NULL) {
		if (atualespera->carro.prioritario) {
			temp->carro = atualespera->carro;
			temp->seguinte = NULL;
			temp->inicio = novo->inicio;
			atualespera = atualespera->seguinte;
			removecarro(*atualespera, atualespera->carro);
		}
		else {
			atualespera = atualespera->seguinte;
		}
		
	}
	//Apos isto so devemos ter uma lista novo so com carros prioritarios e a lista de espera sem nenhum prioritario
	//temos de junta-las
	atualespera = atualespera->inicio;
	novo = novo->inicio;
	if (novo->inicio != NULL) {
		final->carro = novo->carro;
		final->seguinte = NULL;
		final->inicio = final;
		novo = novo->seguinte;
	}
	else if (novo->inicio == NULL && atualespera->inicio!= NULL) {
		final = atualespera;
	}
	else if (novo->inicio == NULL && atualespera->inicio == NULL) {
		final = NULL;
	}
	while (novo != NULL) {
		finaltemp->carro = novo->carro;
		finaltemp->seguinte = NULL;
		finaltemp->inicio = final->inicio;
		final->seguinte = finaltemp;
		final = final->seguinte;
		novo = novo->seguinte;
	}
	while (atualespera != NULL) {
		finaltemp->carro = atualespera->carro;
		finaltemp->seguinte = NULL;
		finaltemp->inicio = final->inicio;
		final->seguinte = finaltemp;
		final = final->seguinte;
		novo = novo->seguinte;
	}
	atualespera = final;
	atualespera = atualespera->inicio;
}

void seguinte(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos)
{
	for (int i = 0; i < Of.numero_ets; i++) {
		//reparacao();

	}
	Of.ciclos++;
	CriarCarrosNaFila(Of, marcas, modelos, 10);
	colocarprioritario(Of);
	ColocarCarrosET(Of, 8);
	
}


////Temporario
//void NovaListaEspera(l) {
//    l.primeiro = 0;
//}
//
//void InsereElementoListaEspera(LEspera& l, Carro c) {
//    // Insere o carro no final da lista de carros
//    LEspera::Elemento* aux = new LEspera::Elemento;
//    aux->viatura = c;
//    aux->seguinte = 0;
//    if (l.primeiro == 0)
//        l.primeiro = aux;
//    else {
//        LEspera::Elemento* temp = l.primeiro;
//        while (temp->seguinte != 0)
//            temp = temp->seguinte;
//        temp->seguinte = aux;
//
//    }
//
//};
//
//
//bool Vazia(LEspera& l)
//{
//    if (l.primeiro == 0)
//        return true;
//    else
//        return false;
//}
//
//
//void Remove(LEspera& l) {
//    // Remove primeiro o carro da lista de carros
//    if (Vazia(l)) throw ERRO_LISTA_VAZIA;
//    LEspera::Elemento* aux = l.primeiro;
//    l.primeiro = aux->seguinte;
//    delete aux;
//   
//};
//
//void InserePrioritario(LEspera& l, Carro c) {
//    // Insere o carro prioritário no início da lista de carros
//    LEspera::Elemento* aux = new LEspera::Elemento;;
//    aux->viatura = c;
//    if (Vazia(l)) {
//        aux->seguinte = 0;
//        l.primeiro = aux;
//    }
//    LEspera::Elemento* temp = l.primeiro;
//    aux->seguinte = temp;
//    l.primeiro = aux;
//};
//
//
//Carro Primeiro(LEspera& l)
//{
//    if (Vazia(l)) throw ERRO_LISTA_VAZIA;
//    return l.primeiro->viatura;
//
//}
//
//int Comprimento(LEspera& l)
//{
//    LEspera::Elemento* aux = l.primeiro;
//    int comprimento = 0;
//    while (aux != 0) {
//        comprimento++;
//        aux = aux->seguinte;
//    }
//    return comprimento;
//
//}
//
//void Escreve(LEspera& l)
//{
//    if (Vazia(l))
//        cout << "-> NULL" << endl;
//    else
//    {
//        LEspera::Elemento* aux = l.primeiro;
//        cout << endl;
//        while (aux != 0)
//        {
//            cout << "Modelo: " << aux->viatura.modelo << " | " << "Marca: " << aux->viatura.marca << " | "
//                << "Prioritario: " << aux->viatura.prioritario << endl;
//            aux = aux->seguinte;
//        }
//    }
//}
//*/