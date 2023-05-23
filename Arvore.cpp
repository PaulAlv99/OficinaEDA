#include "Arvore.h"


Arvore* novoNodo(Carro &carro) {
    Arvore* raiz = new Arvore();
    raiz->carros_reparados = carro;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    return raiz;
}
bool compararalf(string str1,string str2) {
    int i = str1.compare(str2);
    if (i >= 0) {//se o modelo for igual ou se o modelo str1 é maior que str2
        return true;
    }
    else{
        return false; //se o modelo str1 é menor que str2
    }
}
Arvore* inserirNodo(Arvore*& raiz, Carro &carros_reparados) {
    Arvore* aux = raiz;
    Arvore* prev = NULL;
    if (raiz == NULL)
        aux = novoNodo(carros_reparados);
    else {
        while (raiz != NULL) {
            prev = raiz;//i.g ACURA,TESLA
            if (compararalf(raiz->carros_reparados.modelo,carros_reparados.modelo)) {
                raiz->esquerda->carros_reparados = carros_reparados;
            }
            else {
                raiz->direita->carros_reparados = carros_reparados;
            }
        }
        if (compararalf(prev->carros_reparados.modelo,carros_reparados.modelo))
            prev->esquerda = novoNodo(carros_reparados);
        else    
            prev->direita = novoNodo(carros_reparados);
    }
    return aux;
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

    for (int i = 1; i < nivel; i++) {
        std::cout << "\t";
    }
    std::cout << raiz->carros_reparados.marca << "-" << raiz->carros_reparados.modelo << std::endl;

    imprimeArvore(raiz->esquerda, nivel + 1);
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

Carro infixa(Arvore* raiz, Carro* carrosreparados) {
    int i = numeroVertices(raiz);
    if (raiz != NULL) {
        infixa(raiz->esquerda,&raiz->carros_reparados);
        Carro* carrosreparados = new Carro[i];
        for(int t=0; t< i;i++){
            carrosreparados[t] = raiz->carros_reparados;
        }
        infixa(raiz->direita,&raiz->carros_reparados);
    }
    return *carrosreparados;
}

Arvore* removerCopia(Arvore*& raiz, int num) {
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


Arvore* ultimoInfixa(Arvore* raiz) {
    Arvore* ultimo{};
    if (raiz != NULL) {
        ultimoInfixa(raiz->esquerda);
        ultimo=ultimoInfixa(raiz->direita);
       
    }
    ultimo->esquerda = NULL;
    ultimo->direita = NULL;
    return ultimo;
}
