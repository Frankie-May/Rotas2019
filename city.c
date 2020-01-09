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

	strcpy(new->city_name, city_name);
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
| Funcao: view_city
| Argumentos: init -> apontador para o inicio da lista de cidades;
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

/*------------------------------------------------------------
| Funcao: add_city_to_airports
| Argumentos: init -> apontador para o inicio da lista de cidades;
| Return: Void.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

void add_city_to_airports(AIRPORT* init)
{
	AIRPORT *current_airport, *current_city;

	current_airport = init;
	while(current_airport != NULL)
	{
		current_city = init;
		while(current_city != NULL)
		{
			if(current_city->airport_details.city != current_airport->airport_details.city)
			{
				current_airport->next_city = add_city(current_airport->next_city, current_city->airport_details.city);
			}
			current_city = current_city->next;
		}
		current_airport = current_airport->next;
	}
}