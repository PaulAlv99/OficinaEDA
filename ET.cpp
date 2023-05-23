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

void reparacao(EstacaoTrabalho& ET) {
	int chance;

	for (int i = 0; i < ET.capacidade; i++) {
		if ((ET.carros_a_ser_reparados[i].dias_em_reparacao < ET.carros_a_ser_reparados[i].tempo_reparacao_max) && (ET.carros_a_ser_reparados[i].ID != 0)) {
			chance = rand() % 100 + 1;
			if ((chance >= 1 and chance <= 15) && (ET.carros_a_ser_reparados[i].dias_em_reparacao > 0)) {
				int tamanho = (ET.num_carros_reparados);
				Adiciona(ET.Carrosreparados, tamanho, ET.carros_a_ser_reparados[i]);
				
				ET.num_carros_a_ser_reparados = ET.num_carros_a_ser_reparados - 1;
				ET.carros_a_ser_reparados[i].ID = 0;
				ET.faturacao = ET.faturacao + (ET.carros_a_ser_reparados[i].dias_em_reparacao * ET.mecanico.preco_reparacao_por_dia);
				ET.Carrosreparados[ET.num_carros_reparados].custoreparacao = ET.mecanico.preco_reparacao_por_dia * ET.Carrosreparados[ET.num_carros_reparados].dias_em_reparacao;
				ET.num_carros_reparados = ET.num_carros_reparados + 1;

			}
			else
				ET.carros_a_ser_reparados[i].dias_em_reparacao++;
		}

		else if ((ET.carros_a_ser_reparados[i].dias_em_reparacao >= ET.carros_a_ser_reparados[i].tempo_reparacao_max) && (ET.carros_a_ser_reparados[i].ID != 0)) {
			int tamanho = (ET.num_carros_reparados);
			Adiciona(ET.Carrosreparados, tamanho, ET.carros_a_ser_reparados[i]);
			
			ET.num_carros_a_ser_reparados = ET.num_carros_a_ser_reparados - 1;
			ET.carros_a_ser_reparados[i].ID = 0;
			ET.faturacao = ET.faturacao + (ET.carros_a_ser_reparados[i].dias_em_reparacao * ET.mecanico.preco_reparacao_por_dia);
			ET.Carrosreparados[ET.num_carros_reparados].custoreparacao = ET.mecanico.preco_reparacao_por_dia * ET.Carrosreparados[ET.num_carros_reparados].dias_em_reparacao;
			ET.num_carros_reparados = ET.num_carros_reparados + 1;
		}
	}

}
*/


EstacaoTrabalho CriarET(int ID) {
    EstacaoTrabalho nova = EstacaoTrabalho();
    nova.mecanico; // Atribuir um novo objeto Mecanico a nova.mecanico
    nova.capacidade = 2 + (rand() % 3);
    nova.faturacao = 0;
    nova.ID = ID;
    nova.Carrosreparados = nullptr;
    nova.carros_a_ser_reparados = nullptr;
    nova.num_carros_a_ser_reparados = 0;
    nova.seguinte = NULL;
    nova.inicio = NULL;
    return nova;
}
//Tem dois pointers um para o todos os elementos node->inicio e outro para seguinte->NULL
void reparacao(Oficina& Of) {
	int chance;
	EstacaoTrabalho* atualET = &Of.ets;
	listacarros* atualcarro = atualET->carros_a_ser_reparados;
	while (atualET != NULL) {
		while (atualET->carros_a_ser_reparados) {
			if ((atualET->carros_a_ser_reparados->carro.dias_em_reparacao < atualET->carros_a_ser_reparados->carro.tempo_reparacao_max) && (atualET->carros_a_ser_reparados->carro.ID != 0))
				chance = rand() % 100 + 1;
			if ((chance >= 1 && chance <= 15) && (atualET->carros_a_ser_reparados->carro.dias_em_reparacao > 0)) {
				int tamanho = atualET->num_carros_a_ser_reparados;
				/* Adicionar a arvore de carros reparados
				   listacarros* novono = new listacarros();
				   novono->carro = atual->carro;
				   novono->seguinte = ET.Carrosreparados;
				   ET.Carrosreparados = novono;*/

				Of.ets.num_carros_a_ser_reparados--;
				
				Of.ets.faturacao += (atualET->carros_a_ser_reparados->carro.dias_em_reparacao * Of.ets.mecanico.preco_reparacao_por_dia);
				Of.ets.Carrosreparados->carros_reparados.custoreparacao = Of.ets.mecanico.preco_reparacao_por_dia * atualET->carros_a_ser_reparados->carro.dias_em_reparacao;
				if (Of.ets.Carrosreparados == NULL) {
					Of.ets.Carrosreparados = novoNodo(atualET->carros_a_ser_reparados->carro);
					atualET->carros_a_ser_reparados->carro.ID = 0; //remove o carro da lista de carros a ser reparados
				}
				else {
					Of.ets.Carrosreparados = inserirNodo(Of.ets.Carrosreparados, atualET->carros_a_ser_reparados->carro);
					atualET->carros_a_ser_reparados->carro.ID = 0; //remove o carro da lista de carros a ser reparados
				}
				Of.ets.num_carros_reparados++;
				atualET->carros_a_ser_reparados->carro.dias_em_reparacao++;
			}
			else if ((atualET->carros_a_ser_reparados->carro.dias_em_reparacao >= atualET->carros_a_ser_reparados->carro.tempo_reparacao_max) && (atualET->carros_a_ser_reparados->carro.ID != 0)) {
				/* Adicionar a arvore de carros reparados
				   listacarros* novono = new listacarros();
				   novono->carro = atual->carro;
				   novono->seguinte = ET.Carrosreparados;
				   ET.Carrosreparados = novono;*/

				Of.ets.num_carros_a_ser_reparados--;
				atualET->carros_a_ser_reparados->carro.ID = 0; //remove o carro da lista de carros a ser reparados
				Of.ets.faturacao += atualET->carros_a_ser_reparados->carro.dias_em_reparacao * Of.ets.mecanico.preco_reparacao_por_dia;
				Of.ets.Carrosreparados->carros_reparados.custoreparacao = Of.ets.mecanico.preco_reparacao_por_dia * atualET->carros_a_ser_reparados->carro.dias_em_reparacao;
				if (Of.ets.Carrosreparados == NULL) {
					Of.ets.Carrosreparados = novoNodo(atualET->carros_a_ser_reparados->carro);
					atualET->carros_a_ser_reparados->carro.ID = 0; //remove o carro da lista de carros a ser reparados
				}
				else {
					Of.ets.Carrosreparados = inserirNodo(Of.ets.Carrosreparados, atualET->carros_a_ser_reparados->carro);
					atualET->carros_a_ser_reparados->carro.ID = 0; //remove o carro da lista de carros a ser reparados
				}
				Of.ets.num_carros_reparados++;
				atualET->carros_a_ser_reparados->carro.dias_em_reparacao++;
			}
			atualET->carros_a_ser_reparados++;
		}
		atualET++;
	}
}