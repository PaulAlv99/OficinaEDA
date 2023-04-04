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

    Carro* carrinhos = new Carro[10];

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
    /*for (int i = METAL.fila_espera_tamanho; i < METAL.fila_espera_tamanho + 10; i++) {
        carrinhos[METAL.fila_espera_tamanho+i] = CriarCarroRandom(marcas.linhas[rand() % marcas.tamanho], modelos.linhas[rand() % modelos.tamanho]);
        carrinhos[METAL.fila_espera_tamanho+i].ID = METAL.fila_espera_tamanho+i;
        METAL.fila_espera = carrinhos;
        METAL.fila_espera_tamanho++;

    }
    */
    /*limpar os couts*/
    system("CLS");
    /* Fazer um for para aparecer as informacoes na consola(ainda falta algumas informações) */
    for (int i = 0; i < numero_ets; i++) {
        cout << "ET: " << ET[i].ID << " | " << "Mecanico: " << METAL.ets[i].mecanico.nome
        << " | " << "Capacidade: " << METAL.ets[i].capacidade << " | " << "Carros: " <<  METAL.ets[i].numero_carros << " | " <<
         "Marca: " << METAL.ets[i].mecanico.marca << " | " << "Total Faturacao: " << METAL.ets[i].faturacao << endl;
    }
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "Lista de Espera: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << "ID: " << METAL.fila_espera[i].ID << " | " << "Modelo: " <<  METAL.fila_espera[i].modelo << " | " << "Marca: " << METAL.fila_espera[i].marca << " | "
        << "Prioritario: " << METAL.fila_espera[i].prioritario << endl;
    }
    menu(METAL);

    return 0;

}
