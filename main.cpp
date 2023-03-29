#include "Ficheiros.h"
#include "Oficina.h"

int main()
{
    srand(time(0));
    LinhasFicheiro marcas = CarregarFicheirosLista("marcas.txt");
    
    LinhasFicheiro modelos = CarregarFicheirosLista("modelo.txt");

    Oficina METAL = criarOficina();
    int numero_ets = METAL.numero_ets;
    Mecanico* Mecanicos = new Mecanico[numero_ets];
    EstacaoTrabalho* ET = new EstacaoTrabalho[numero_ets];
    for (int i = 0; i < numero_ets; i++) {
        Mecanicos[i] = CriarMecanico(marcas);
        ET[i] = CriarET(i);
        ET[i].mecanico = Mecanicos[i];
        METAL.ets[i] = ET[i];
    }

    return 0;

}
