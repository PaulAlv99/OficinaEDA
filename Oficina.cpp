#include "Oficina.h"


int numero_de_et() {
    int et_numero = 3 + (rand() % 5); // numero de ET por oficina random
    return et_numero;
}

Oficina criarOficina(LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
    Oficina nova = Oficina();
    nova.ciclos = 0; //dias de trabalho
    nova.numero_ets = numero_de_et();
    nova.ets = new EstacaoTrabalho[nova.numero_ets];
    nova.fila_espera = new Carro[0];
    nova.fila_espera_tamanho = 0;



    /* Criar os mecanicos conforme o numero de ets gerado*/
    for (int i = 0; i < nova.numero_ets; i++) {
        nova.ets[i] = CriarET(i+1);
        nova.ets[i].mecanico = CriarMecanico(marcas);
    }
    /*Criar 10 carros random*/
    CriarCarrosNaFila(nova,marcas,modelos,nova.fila_espera_tamanho);


    //Criar ET; criar os mecanicos; encher a fila ; criar os carros (lista das marcas e dos modelos);
    return nova;
}

void seguinte(Oficina& Of, LinhasFicheiro& marcas,LinhasFicheiro& modelos)
{
	Of.ciclos++;
	CriarCarrosNaFila(Of,marcas,modelos,10);

	// Proceder às restantes operações de um ciclo
}

//sugiro usar a funcao bool  GerarProbalidades(double probalidade);
void reparacao(EstacaoTrabalho ID1, Oficina METAL, Carro ID2) {
	int chance;
	int i = 0;
	if (ID1.Carrosreparados->size() > 0)
		int i = (ID1.Carrosreparados->size()) - 1;
	if (ID2.dias_em_reparacao < ID2.tempo_reparacao_max) {
		chance = rand() % 100 + 1;
		if (chance >= 1 and chance <= 15) {
			//remover carro da lista de espera
			//sugiro a usar as funcoes definidas em Carro.cpp. Adiciona;Remove e Transfere
			//para usar aqui na oficina acho que basta esta declarado no header a funcao e os parametros
			//e passar sempre como argumentos o endereço (&)
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

bool MarcaPresente(Oficina &Of, string marca) {
	bool temp = false;
	for (int i = 0; i < Of.numero_ets; i++) {
		temp = (marca == Of.ets[i].mecanico.marca);
		if (temp) {
			break;
		}
	}

	return temp;
}


void CriarCarrosNaFila(Oficina& Of, LinhasFicheiro& marcas, LinhasFicheiro& modelos, int num) {
	while (num) {
		Carro novo = CriarCarro(marcas, modelos);
		for (int i = 1; i <= num; i++) {
			novo.ID = i;
		}
		if (MarcaPresente(Of, novo.marca)) {
			Adiciona(Of.fila_espera, Of.fila_espera_tamanho, novo);
			num--;
		}
	}
}
