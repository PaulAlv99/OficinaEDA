#pragma once
#include "ListLigada.h"

struct Arvore {
    Carro carros_reparados;
    Arvore* esq;
    Arvore* dir;
};