/* File city.c*/

#include "airport.h"

/*------------------------------------------------------------
| Funcao: add_city
| Argumentos: init -> apontador para o inicio da lista de cidades;
| 			  city_name -> nome da cidade a acrescentar;
| Return: O ponto de acesso ao inicio da lista de cidades.
| Autor: Francisco May e Gustavo Duarte
| Data: 2019/12/18
| Versão: 0.0
--------------------------------------------------------------*/

CITY* add_city(CITY *init, char city_name[])
{
	CITY *new, *current, *before;

	new = (CITY*)calloc(1, sizeof(CITY));

	new->city_name = city_name;
	new->next = NULL;
	new->next_flight = NULL;

	current = init;
	before = NULL;
	while((current != NULL) && (strcmp(current->city_name, new->city_name) < 0))
	{
		before = current;
		current = current->next;
	}

	if(current == init)
	{
		new->next = current;
		init = new;
	}
	else
	{
		new->next = current;
		before->next = new;
	}

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

void view_city(CITY* init)
{
	CITY* aux;

	aux = init;

	while(aux != NULL)
	{
		printf("%s\n", aux->city_name);
		aux = aux->next;
	}
}