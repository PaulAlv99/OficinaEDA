#pragma once
#include "ListLigada.h"

struct Arvore {
    Carro carros_reparados;
    Arvore* esquerda;
    Arvore* direita;
};
Arvore* novoNodo(Carro carro);
Arvore* inserirNodo(Arvore* raiz, Carro carros_reparados);
int numeroNiveis(Arvore* raiz);
int numeroVertices(Arvore* raiz);//� o mesmo que conta n�s
void imprimeArvore(Arvore* no, int nivel);
Arvore* removerCopia(Arvore* raiz, int num);
Arvore* removerCopia2(Arvore* raiz, Arvore* no, Arvore* ant);
int numeroNiveis(Arvore* raiz);
void infixa(Arvore* raiz);