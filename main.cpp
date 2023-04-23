#include "Ficheiros.h"
#include "Carro.h"
#include "Oficina.h"
#include "Gestao.h"
#include <iostream>
#include <string>
#include "Ciclos.h"



int main(int argc, char* argv[])
{

    srand(time(0));
    /* Inicilizar as structs */
    /* Com as marcas e modelos a utilizar */

    LinhasFicheiro marcas = CarregarFicheirosLista("marcas.txt");
    
    LinhasFicheiro modelos = CarregarFicheirosLista("modelo.txt");

    /* Inicilizar a Oficina */

    Oficina METAL = Oficina();

    if (argc == 2) {

        string caminho = argv[1];
        carregar_oficina(METAL, caminho);
     
    }
    else {
        
        /*limpar os couts*/
        system("CLS");

        METAL = criarOficina(marcas, modelos);

        colocarprioritario(METAL);
    }

    MenuInfo(METAL, marcas, modelos);

    Menu(METAL, marcas, modelos);


    return 0;
}


//
//
//int main()
//{
//
//
//    srand(time(0));
//    /* Inicilizar as structs */
//    /* Com as marcas e modelos a utilizar */
//
//    LinhasFicheiro marcas = CarregarFicheirosLista("marcas.txt");
//
//    LinhasFicheiro modelos = CarregarFicheirosLista("modelo.txt");
//
//    /* Inicilizar a Oficina */
//
//    Oficina METAL = criarOficina(marcas, modelos);
//
//        /*limpar os couts*/
//
//        system("CLS");
//        //CriarCarrosNaFila(METAL, marcas, modelos, 10);
//        colocarprioritario(METAL);
//        MenuInfo(METAL, marcas, modelos);
//
//        Menu(METAL, marcas, modelos);
//   
//
//
//    /*for (int i = 0; i < 10; i++) {
//        carrinhos[i] = CriarCarroRandom(marcas.linhas[rand() % marcas.tamanho], modelos.linhas[rand() % modelos.tamanho]);
//        carrinhos[i].ID = i;
//        METAL.fila_espera = carrinhos;
//        METAL.fila_espera_tamanho++;
//    } */
//
//    /*Criar 10 carros das marcas que tem na oficina*/
//
//    /*for (int i = 10; i < 20; i++) {
//        carrinhos[i] = CriarCarro(Mecanicos, modelos.linhas[rand() % modelos.tamanho], numero_ets);
//        carrinhos[i].ID = i;
//        METAL.fila_espera = carrinhos;
//        METAL.fila_espera_tamanho++;
//    } */
//
//    /* for (int i = METAL.fila_espera_tamanho; i < METAL.fila_espera_tamanho + 10; i++) {
//         carrinhos[METAL.fila_espera_tamanho+i] = CriarCarro(Mecanicos, modelos.linhas[rand % modelos.tamanho]);
//         carrinhos[METAL.fila_espera_tamanho+i].ID = METAL.fila_espera_tamanho+i;
//         METAL.fila_espera = carrinhos;
//         METAL.fila_espera_tamanho++;
//     }*/
//
//
//
//     ///*limpar os couts*/
//
//     //system("CLS");
//     ////CriarCarrosNaFila(METAL, marcas, modelos, 10);
//     //colocarprioritario(METAL);
//     //MenuInfo(METAL,marcas,modelos);
//     //
//     //Menu(METAL,marcas,modelos);
//
//    return 0;
//
//}

