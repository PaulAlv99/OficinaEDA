#include "Oficina.h"


int numero_de_et() {
    int et_numero = (rand() % 8 + 3); // numero de ET por oficina random
    return et_numero;
}

Oficina criarOficina() {
    Oficina nova = Oficina();
    nova.ciclos = 0;
    nova.numero_ets = numero_de_et();
    nova.ets = new EstacaoTrabalho[nova.numero_ets];
    nova.fila_espera = new Carro[0];
    nova.fila_espera_tamanho = 0;

    //Criar ET; criar os mecanicos; encher a fila ; criar os carros (lista das marcas e dos modelos);
    return nova;
}
