#pragma once
#include "Oficina.h"


struct nodoDuplo {
	/*nodoDuplo* head;*/
	Carro carros_a_ser_reparados;
	nodoDuplo* seguinte;
	nodoDuplo* anterior;
	
};

//� preciso fazer lista ligada para as ETs tambem