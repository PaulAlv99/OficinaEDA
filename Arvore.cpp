#include "Arvore.h"
Arvore* novoNodo(Carro carro) {
	Arvore* novonodo = new Arvore(); 
	novonodo->carros_reparados = carro; //criar um nodo e meter um carro;
	novonodo->direita = NULL;
	novonodo->esquerda = NULL;
	return novonodo;
}
Arvore* inserirNodo(Arvore* raiz, Carro carros_reparados) {
	if (carros_reparados.ID > raiz->carros_reparados.ID) {
		raiz->direita = inserirNodo(raiz->direita, carros_reparados);
	}
	else if (carros_reparados.ID < raiz->carros_reparados.ID) {
		raiz->esquerda = inserirNodo(raiz->esquerda, carros_reparados);
	}
	if (raiz == NULL) {
		novoNodo(carros_reparados);
	}
	return raiz;
}
int numeroNiveis(Arvore* raiz) {
	if (raiz == NULL) {
		return 0;
	}
	else {
		return 1 + int(max(numeroNiveis(raiz->esquerda), numeroNiveis(raiz->direita)));
	}
}
int numeroVertices(Arvore* raiz)
{
	if (raiz == NULL)
		return 0;

	int l = numeroVertices(raiz->esquerda);
	int r = numeroVertices(raiz->direita);

	return 1 + l + r;
}
void imprimeArvore(Arvore* raiz, int nivel) {
	int nivel = numeroNiveis(raiz);
	if (raiz == NULL) {
		cout << endl;
		return;
	}
	imprimeArvore(raiz->direita, nivel + 1);
	for (int i = 1; i < nivel; i++)
	{
		cout << "\t";
	}
	cout << raiz->carros_reparados.marca << "-" << raiz->carros_reparados.modelo << endl;
	imprimeArvore(raiz->esquerda, nivel + 1);
}

Arvore* removerCopia(Arvore* raiz, int num) {
	Arvore* no = raiz;
	Arvore* ant = NULL;
	while (no != NULL) {
		if (num == no->carros_reparados.ID) {
			return raiz = removerCopia2(raiz, no, ant);
		}
		else if (num < no->carros_reparados.ID) {
			ant = no;
			no = no->esquerda;
		}
		else {
			ant = no;
			no = no->direita;
		}
	}
	return raiz;
}

Arvore* removerCopia2(Arvore* raiz, Arvore* no, Arvore* ant) {
	if (ant == NULL) { //remover a raiz
		if (no->esquerda == NULL && no->direita == NULL)
			raiz = NULL;
		else if (no->esquerda != NULL && no->direita == NULL)
			raiz = no->esquerda;
		else if (no->esquerda == NULL && no->direita != NULL)
			raiz = no->direita;
		else { //efetuar copia
			Arvore* temp = no->esquerda;
			ant = raiz;
			while (temp->direita != NULL) {
				ant = temp;
				temp = temp->direita;
			}
			swap(temp->carros_reparados.ID, raiz->carros_reparados.ID);
			if (ant->carros_reparados.ID >= raiz->carros_reparados.ID || ant == raiz)
				ant->esquerda = temp->esquerda;
			else
				ant->direita = temp->esquerda;
			no = temp;
		}
	}
	else { // remover qualquer outro n�
		if (no->esquerda == NULL && no->direita == NULL) {
			if (ant->carros_reparados.ID > no->carros_reparados.ID)
				ant->esquerda = NULL;
			else
				ant->direita = NULL;
		}
		else if (no->esquerda == NULL && no->direita != NULL) {
			if (ant->carros_reparados.ID > no->carros_reparados.ID)
				ant->esquerda = no->direita;
			else
				ant->direita = no->direita;
		}
		else if (no->esquerda != NULL && no->direita == NULL) {
			if (ant->carros_reparados.ID > no->carros_reparados.ID)
				ant->esquerda = no->esquerda;
			else
				ant->direita = no->esquerda;
		}
		else { // efetuar copia
			Arvore* temp = no->esquerda;
			ant = no;
			while (temp->direita != NULL) {
				ant = temp;
				temp = temp->direita;
			}
			swap(temp->carros_reparados.ID, no->carros_reparados.ID);
			if (ant->carros_reparados.ID > no->carros_reparados.ID || ant == no)
				ant->esquerda = temp->esquerda;
			else
				ant->direita = temp->esquerda;
			no = temp;
		}

	}
	delete no;
	return raiz;
}

void infixa(Arvore* raiz)//travessia infixa
{
	if (raiz != NULL) {
		infixa(raiz->esquerda);
		cout << raiz->carros_reparados.ID << " ";
		infixa(raiz->direita);
	}
}