#include "ListLigada.h"

//numa ET
int num_carros_a_ser_reparados(nodoDuplo* head) {
	nodoDuplo* current = head;
	int count = 0;
	while (current->seguinte != NULL) {
		count++;
		current = current->seguinte;
	}
	return count;
}

void insereFim(nodoDuplo*& head, Carro& carro_a_receber) {
	nodoDuplo* iterator = head;
	while (iterator->seguinte != NULL) {
	iterator = iterator->seguinte;
	}
	nodoDuplo* newNode = new nodoDuplo;
	newNode->seguinte = NULL;
	newNode->carros_a_ser_reparados = carro_a_receber;

	iterator->seguinte = newNode;

}

nodoDuplo insereInicio(nodoDuplo*& head, Carro& carro_a_receber) {
	nodoDuplo* newNode = new nodoDuplo;
	newNode->carros_a_ser_reparados = carro_a_receber;
	newNode->seguinte = head;
	newNode->anterior = NULL;

	if (head != NULL) {
		head->anterior = newNode;
	}
	head = newNode;

}
//insert a node after a given node in the linked list
void insereMeio(nodoDuplo*& anterior_onde_quero_inserir, Carro& carro_a_receber)
{
	/*1. check if the given prev_node is NULL */
	if (anterior_onde_quero_inserir == NULL) {
		cout << "the given previous node cannot be NULL";
		return;
	}

	/* 2. allocate new node */
	nodoDuplo* newNode = new nodoDuplo;

	/* 3. put in the data */
	newNode->carros_a_ser_reparados = carro_a_receber;

	/* 4. Make next of new node as next of prev_node */
	newNode->seguinte = anterior_onde_quero_inserir->seguinte;

	/* 5. Make the next of prev_node as new_node */
	anterior_onde_quero_inserir->seguinte = newNode;

	/* 6. Make prev_node as previous of new_node */
	newNode->anterior = anterior_onde_quero_inserir;

	/* 7. Change previous of new_node's next node */
	if (newNode->seguinte != NULL)
		newNode->seguinte->anterior = newNode;
}
