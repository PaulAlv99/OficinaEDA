#include "ET.h"

/*EstacaoTrabalho CriarET(int ID) {
	EstacaoTrabalho nova = EstacaoTrabalho();
	nova.mecanico;
	nova.capacidade = 2 + (rand() % 3);
	nova.faturacao = 0;
	nova.ID = ID;
	nova.Carrosreparados = new Carro[0];
	nova.carros_a_ser_reparados = new Carro[nova.capacidade];
	nova.num_carros_a_ser_reparados = 0;
	return nova;
}

void reparacao(EstacaoTrabalho& ID1) {
	int chance;

	for (int i = 0; i < ID1.capacidade; i++) {
		if ((ID1.carros_a_ser_reparados[i].dias_em_reparacao < ID1.carros_a_ser_reparados[i].tempo_reparacao_max) && (ID1.carros_a_ser_reparados[i].ID != 0)) {
			chance = rand() % 100 + 1;
			if ((chance >= 1 and chance <= 15) && (ID1.carros_a_ser_reparados[i].dias_em_reparacao > 0)) {
				int tamanho = (ID1.num_carros_reparados);
				Adiciona(ID1.Carrosreparados, tamanho, ID1.carros_a_ser_reparados[i]);
				
				ID1.num_carros_a_ser_reparados = ID1.num_carros_a_ser_reparados - 1;
				ID1.carros_a_ser_reparados[i].ID = 0;
				ID1.faturacao = ID1.faturacao + (ID1.carros_a_ser_reparados[i].dias_em_reparacao * ID1.mecanico.preco_reparacao_por_dia);
				ID1.Carrosreparados[ID1.num_carros_reparados].custoreparacao = ID1.mecanico.preco_reparacao_por_dia * ID1.Carrosreparados[ID1.num_carros_reparados].dias_em_reparacao;
				ID1.num_carros_reparados = ID1.num_carros_reparados + 1;

			}
			else
				ID1.carros_a_ser_reparados[i].dias_em_reparacao++;
		}

		else if ((ID1.carros_a_ser_reparados[i].dias_em_reparacao >= ID1.carros_a_ser_reparados[i].tempo_reparacao_max) && (ID1.carros_a_ser_reparados[i].ID != 0)) {
			int tamanho = (ID1.num_carros_reparados);
			Adiciona(ID1.Carrosreparados, tamanho, ID1.carros_a_ser_reparados[i]);
			
			ID1.num_carros_a_ser_reparados = ID1.num_carros_a_ser_reparados - 1;
			ID1.carros_a_ser_reparados[i].ID = 0;
			ID1.faturacao = ID1.faturacao + (ID1.carros_a_ser_reparados[i].dias_em_reparacao * ID1.mecanico.preco_reparacao_por_dia);
			ID1.Carrosreparados[ID1.num_carros_reparados].custoreparacao = ID1.mecanico.preco_reparacao_por_dia * ID1.Carrosreparados[ID1.num_carros_reparados].dias_em_reparacao;
			ID1.num_carros_reparados = ID1.num_carros_reparados + 1;
		}
	}

}
*/

struct listacarros {
    Carro carro;
    listacarros* proximo;
};

EstacaoTrabalho CriarET(int ID) {
    EstacaoTrabalho nova;
    nova.mecanico = Mecanico(); // Atribuir um novo objeto Mecanico a nova.mecanico
    nova.capacidade = 2 + (rand() % 3);
    nova.faturacao = 0;
    nova.ID = ID;
    nova.Carrosreparados = nullptr;
    nova.carros_a_ser_reparados = nullptr;
    nova.num_carros_a_ser_reparados = 0;
    return nova;
}

void reparacao(EstacaoTrabalho& ID1) {
    int chance;
    listacarros* atual = ID1.carros_a_ser_reparados;
    listacarros* anterior = nullptr;

    while (atual != nullptr) {
        if ((atual->carro.dias_em_reparacao < atual->carro.tempo_reparacao_max) && (atual->carro.ID != 0)) {
            chance = rand() % 100 + 1;
            if ((chance >= 1 && chance <= 15) && (atual->carro.dias_em_reparacao > 0)) {
                listacarros* novolistacarros = new listacarros();
                novolistacarros->carro = atual->carro;
                novolistacarros->proximo = ID1.Carrosreparados;
                ID1.Carrosreparados = novolistacarros;

                ID1.num_carros_a_ser_reparados--;
                atual->carro.ID = 0;
                ID1.faturacao += atual->carro.dias_em_reparacao * ID1.mecanico.preco_reparacao_por_dia;
                ID1.Carrosreparados->carro.custoreparacao = ID1.mecanico.preco_reparacao_por_dia * atual->carro.dias_em_reparacao;
                ID1.num_carros_reparados++;
            }
            else {
                atual->carro.dias_em_reparacao++;
            }
        }
        else if ((atual->carro.dias_em_reparacao >= atual->carro.tempo_reparacao_max) && (atual->carro.ID != 0)) {
            listacarros* novolistacarros = new listacarros();
            novolistacarros->carro = atual->carro;
            novolistacarros->proximo = ID1.Carrosreparados;
            ID1.Carrosreparados = novolistacarros;

            ID1.num_carros_a_ser_reparados--;
            atual->carro.ID = 0;
            ID1.faturacao += atual->carro.dias_em_reparacao * ID1.mecanico.preco_reparacao_por_dia;
            ID1.Carrosreparados->carro.custoreparacao = ID1.mecanico.preco_reparacao_por_dia * atual->carro.dias_em_reparacao;
            ID1.num_carros_reparados++;
        }

        anterior = atual;
        atual = atual->proximo;
        delete anterior;
    }

    ID1.carros_a_ser_reparados = nullptr;
}


