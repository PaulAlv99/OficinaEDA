#include "Ficheiros.h"
#include "Carro.h"
#include "Oficina.h"
#include "Gestao.h"
#include <iostream>
#include <string>
#include "Ciclos.h"

int main()
{
    system("color 0E");
    
    srand(time(0));
    /* Inicilizar as structs */
    LinhasFicheiro marcas = CarregarFicheirosLista("marcas.txt");
    
    LinhasFicheiro modelos = CarregarFicheirosLista("modelo.txt");

    Oficina METAL = criarOficina(marcas,modelos);

    
    /*for (int i = 0; i < 10; i++) {
        carrinhos[i] = CriarCarroRandom(marcas.linhas[rand() % marcas.tamanho], modelos.linhas[rand() % modelos.tamanho]);
        carrinhos[i].ID = i;
        METAL.fila_espera = carrinhos;
        METAL.fila_espera_tamanho++;
    } */

    /*Criar 10 carros das marcas que tem na oficina*/

    /*for (int i = 10; i < 20; i++) {
        carrinhos[i] = CriarCarro(Mecanicos, modelos.linhas[rand() % modelos.tamanho], numero_ets);
        carrinhos[i].ID = i;
        METAL.fila_espera = carrinhos;
        METAL.fila_espera_tamanho++;
    } */

   /* for (int i = METAL.fila_espera_tamanho; i < METAL.fila_espera_tamanho + 10; i++) {
        carrinhos[METAL.fila_espera_tamanho+i] = CriarCarro(Mecanicos, modelos.linhas[rand % modelos.tamanho]);
        carrinhos[METAL.fila_espera_tamanho+i].ID = METAL.fila_espera_tamanho+i;
        METAL.fila_espera = carrinhos;
        METAL.fila_espera_tamanho++;
    }*/
    /*limpar os couts*/
    CriarCarrosNaFila(METAL, marcas, modelos,10);
    /*system("CLS");*/
    MenuInfo(METAL);

    Menu(METAL);



    return 0;

}
