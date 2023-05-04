#include "Arvore.h"

//carros reparados e carros removidos

struct Arvore {
    Carro carros_reparados;
    Arvore* esq;
    Arvore* dir;
};