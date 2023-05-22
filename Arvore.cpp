#include "Arvore.h"
Arvore* novoNodo(Carro carro) {
    Arvore* novonodo = new Arvore();
    novonodo->carros_reparados = carro;
    novonodo->esquerda = NULL;
    novonodo->direita = NULL;
    return novonodo;
}

Arvore* inserirNodo(Arvore* raiz, Carro carros_reparados) {
    if (raiz == NULL) {
        return novoNodo(carros_reparados);
    }

    if (carros_reparados.ID > raiz->carros_reparados.ID) {
        raiz->direita = inserirNodo(raiz->direita, carros_reparados);
    }
    else if (carros_reparados.ID < raiz->carros_reparados.ID) {
        raiz->esquerda = inserirNodo(raiz->esquerda, carros_reparados);
    }

    return raiz;
}

int numeroNiveis(Arvore* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else {
        return 1 + max(numeroNiveis(raiz->esquerda), numeroNiveis(raiz->direita));
    }
}

int numeroVertices(Arvore* raiz) {
    if (raiz == NULL)
        return 0;

    int l = numeroVertices(raiz->esquerda);
    int r = numeroVertices(raiz->direita);

    return 1 + l + r;
}

void imprimeArvore(Arvore* raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }

    imprimeArvore(raiz->direita, nivel + 1);
    for (int i = 0; i < nivel; i++) {
        cout << "\t";
    }
    cout << raiz->carros_reparados.ID << endl;
    imprimeArvore(raiz->esquerda, nivel + 1);
}

Arvore* removerCopia2(Arvore* raiz, Arvore* no, Arvore* ant);

Arvore* removerCopia(Arvore* raiz, int num) {
    Arvore* no = raiz;
    Arvore* ant = NULL;

    while (no != NULL) {
        if (num == no->carros_reparados.ID) {
            return removerCopia2(raiz, no, ant);
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
    if (ant == NULL) { // remover a raiz
        if (no->esquerda == NULL && no->direita == NULL)
            raiz = NULL;
        else if (no->esquerda != NULL && no->direita == NULL)
            raiz = no->esquerda;
        else if (no->esquerda == NULL && no->direita != NULL)
            raiz = no->direita;
        else { // efetuar copia
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
    else { // remover qualquer outro nó
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

void infixa(Arvore* raiz) {
    if (raiz != NULL) {
        infixa(raiz->esquerda);
        cout << raiz->carros_reparados.ID << " ";
        infixa(raiz->direita);
    }
}
