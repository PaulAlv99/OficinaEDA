#pragma once
#include "Oficina.h"


struct nodoDuplo {
	/*nodoDuplo* head;*/
	nodoDuplo* seguinte;
	nodoDuplo* anterior;
	Carro carros_a_ser_reparados;//que vai ser uma array e os 
};
// acho que aqui dá para fazer Carro* carros_a_ser_reparados e depois fazer o seguinte
//apontar para a proxima ET
//ou
//fazer cada ET aponta para o primeiro carro a ser reparado e depois o seguinte para o proximo carro dessa ET

