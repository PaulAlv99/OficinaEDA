#include "Ficheiros.h"
#include "Carro.h"
#include "Oficina.h"
#include "Gestao.h"
#include <iostream>
#include <string>

int main()
{
    srand(time(0));
    /* Inicilizar as structs */
    LinhasFicheiro marcas = CarregarFicheirosLista("marcas.txt");
    
    LinhasFicheiro modelos = CarregarFicheirosLista("modelo.txt");

    Oficina METAL = criarOficina();

    int numero_ets = METAL.numero_ets;

    Mecanico* Mecanicos = new Mecanico[numero_ets];

    EstacaoTrabalho* ET = new EstacaoTrabalho[numero_ets];

    Carro* carrinhos = new Carro[20];

    /* Criar os mecanicos conforme o numero de ets gerado*/
    for (int i = 0; i < numero_ets; i++) {
        Mecanicos[i] = CriarMecanico(marcas);
        ET[i] = CriarET(i);
        ET[i].mecanico = Mecanicos[i];
        METAL.ets[i] = ET[i];
    }
    /*Criar 10 carros random*/
    for (int i = 0; i < 10; i++) {
        carrinhos[i] = CriarCarroRandom(marcas.linhas[rand() % marcas.tamanho], modelos.linhas[rand() % modelos.tamanho]);
        carrinhos[i].ID = i;
        METAL.fila_espera = carrinhos;
        METAL.fila_espera_tamanho++;
    }

   /* for (int i = METAL.fila_espera_tamanho; i < METAL.fila_espera_tamanho + 10; i++) {
        carrinhos[METAL.fila_espera_tamanho+i] = CriarCarro(Mecanicos, modelos.linhas[rand % modelos.tamanho]);
        carrinhos[METAL.fila_espera_tamanho+i].ID = METAL.fila_espera_tamanho+i;
        METAL.fila_espera = carrinhos;
        METAL.fila_espera_tamanho++;
    }*/
    /*limpar os couts*/
    system("CLS");
    MenuInfo(numero_ets, ET, METAL);
    Menu(numero_ets,ET,METAL);

    return 0;

}
