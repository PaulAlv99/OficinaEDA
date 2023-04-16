#include "Oficina.h"


int numero_de_et() {
    int et_numero = 3 + (rand() % 5); // numero de ET por oficina random
    return et_numero;
}

Oficina criarOficina() {
    Oficina nova = Oficina();
    nova.ciclos = 0; //dias de trabalho
    nova.numero_ets = numero_de_et();
    nova.ets = new EstacaoTrabalho[nova.numero_ets];
    nova.fila_espera = new Carro[20];
    nova.fila_espera_tamanho = 20;

    //Criar ET; criar os mecanicos; encher a fila ; criar os carros (lista das marcas e dos modelos);
    return nova;
}
