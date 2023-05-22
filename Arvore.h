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
int numeroVertices(Arvore* raiz);//é o mesmo que conta nós
void imprimeArvore(Arvore* raiz);
Arvore* removerCopia(Arvore* raiz, int num);
Arvore* removerCopia(Arvore* raiz, Arvore* no, Arvore* ant);
int numeroNiveis(Arvore* raiz);
void imprimeArvore(Arvore* no);