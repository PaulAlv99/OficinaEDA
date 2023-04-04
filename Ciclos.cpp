#include "Ciclos.h"


void reparacao(EstacaoTrabalho ID1, Oficina METAL, Carro ID2) {
	int chance;
	int i = 0;
	if (ID1.Carrosreparados->size() > 0)
		int i = (ID1.Carrosreparados->size()) - 1;
	if (ID2.dias_em_reparacao < ID2.tempo_reparacao_max) {
		chance = rand() % 100 + 1;
		if (chance >= 1 and chance <= 15) {
			//remover carro da lista de espera
			ID1.Carrosreparados[i] = ID2.ID;
			ID1.faturacao = ID1.faturacao + (ID2.dias_em_reparacao * ID1.mecanico.preco_reparacao_por_dia);
		}
		else
			ID2.dias_em_reparacao++;
	}
	if (ID2.dias_em_reparacao >= ID2.tempo_reparacao_max)
		ID1.Carrosreparados[i] = ID2.ID;
	ID1.faturacao = ID1.faturacao + (ID2.dias_em_reparacao * ID1.mecanico.preco_reparacao_por_dia);

}