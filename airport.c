/*File: airport.c*/

#include "airport.h"

/*------------------------------------------------------------
| Funcao: init_airport
| Argumentos: Sem Argumentos.
| Return: Ponto de acesso ao novo aeroporto.
| Autor: Francisco May
| Data: 2019/12/18
| Versão: 0.0
--------------------------------------------------------------*/
AIRPORT* init_airport()
{
	return NULL;
}

/*------------------------------------------------------------
| Funcao: add_airport
| Argumentos: init -> apontador para o inicio da lista de aeroportos;
| airport_data -> informação sobre o aeroporto a acrescentar;
| Return: O ponto de acesso ao inicio da lista de aeroportos.
| Autor: Francisco May e Gustavo Duarte
| Data: 2019/12/18
| Versão: 0.0
--------------------------------------------------------------*/

AIRPORT* add_airport(AIRPORT* init, INFO_AIRPORT airport_data)
{

	AIRPORT* new, *before, *current;

	new = (AIRPORT *)calloc(1, sizeof(AIRPORT));
	if(new == NULL){
		printf("Allocation Error! :-(");
		exit(-1);
	}
	new->airport_details = airport_data;
	new->upcoming_flight = NULL;
	new->next_city = NULL;
	new->next = NULL;

	current = init;
	before = NULL;
	while(current != NULL && (strcmp(current->airport_details.city, new->airport_details.city) < 0)){

		before = current;
		current = current->next;
	}

	if(current == init){
		new->next = current;
		init = new;
		return init;

	}

	new->next = current;
	before->next = new;

	return init;
}

/*------------------------------------------------------------
| Funcao: view_airports
| Argumentos: init -> apontador para o inicio da lista de aeroportos;
| Return: Void.
| Autor: Francisco May e Gustavo Duarte
| Data: 2019/12/18
| Versão: 0.0
--------------------------------------------------------------*/

void view_airports(AIRPORT* init)
{

	AIRPORT* aux;
	
	aux = init;

	while(aux != NULL){
		printf("%s %s %d %d %d %c %d %d %d %c %s %d\n", aux->airport_details.id_ICAO, aux->airport_details.id_IATA, aux->airport_details.latitude.degree, aux->airport_details.latitude.minutes, aux->airport_details.latitude.seconds, aux->airport_details.latitude.orientation, aux->airport_details.longitude.degree, aux->airport_details.longitude.minutes, aux->airport_details.longitude.seconds, aux->airport_details.longitude.orientation, aux->airport_details.city, aux->airport_details.time_zone); 
		aux = aux->next;
	}

}


