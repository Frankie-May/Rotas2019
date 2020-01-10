/*File flight.c*/

#include "airport.h"

/*------------------------------------------------------------
| Funcao: add_flight
| Argumentos: init -> apontador para o inicio da lista de voos;
| 			  flight_data -> informação relativa ao voo;
| Return: O ponto de acesso ao inicio da lista de voos.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

FLIGHT* add_flight(FLIGHT *init, INFO_FLIGHT flight_data)
{
	FLIGHT *new, *current, *before;

	new = (FLIGHT*)calloc(1, sizeof(FLIGHT));

	new->flight_details = flight_data;
	new->next_flight = NULL;

	current = init;
	before = NULL;
	while((current != NULL) && (time_comparison(current->flight_details.departure_time, new->flight_details.departure_time) < 0))
	{
		before = current;
		current = current->next_flight;
	}

	if(current == init)
	{
		new->next_flight = current;
		init = new;
	}
	else
	{
		new->next_flight = current;
		before->next_flight = new;
	}

	return init;

}

/*------------------------------------------------------------
| Funcao: add_flight_invert
| Argumentos: init -> apontador para o inicio da lista de voos;
| 			  flight_data -> informação relativa ao voo;
| Return: O ponto de acesso ao inicio da lista de voos.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

FLIGHT* add_flight_invert(FLIGHT *init, INFO_FLIGHT flight_data)
{
	FLIGHT *new, *current, *before;

	new = (FLIGHT*)calloc(1, sizeof(FLIGHT));

	new->flight_details = flight_data;
	new->next_flight = NULL;

	current = init;
	before = NULL;
	while((current != NULL) && (time_comparison(current->flight_details.departure_time, new->flight_details.departure_time) > 0))
	{
		before = current;
		current = current->next_flight;
	}

	if(current == init)
	{
		new->next_flight = current;
		init = new;
	}
	else
	{
		new->next_flight = current;
		before->next_flight = new;
	}

	return init;

}

/*------------------------------------------------------------
| Funcao: view_flight
| Argumentos: init -> apontador para o inicio da lista de voos;
| Return: Void.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

void view_flight(FLIGHT* init)
{
	FLIGHT* aux;

	aux = init;

	while(aux != NULL)
	{
		printf("%s %s %s %02d:%02d %s %02d:%02d Dist Between:%f\n", aux->flight_details.airline_name, aux->flight_details.flight_code, aux->flight_details.departure, aux->flight_details.departure_time.hours, aux->flight_details.departure_time.minutes, aux->flight_details.arrival, aux->flight_details.arrival_time.hours, aux->flight_details.arrival_time.minutes, aux->flight_details.dist_bet_airports);
		aux = aux->next_flight;
	}
}

/*------------------------------------------------------------
| Funcao: time_comparison
| Argumentos: first_time -> Primeira hora a ser comparada;
| 			  second_time -> Segunda hora a ser comparada;
| Return: Um inteiro que determina a ordem dos voos.
			-1	-> 1ª hora inferior à segunda;
			0 	-> 1ª hora igual à segunda;
			1 	-> 1ª hora superior à segunda;
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

int time_comparison(TIME first_time,TIME second_time)
{
	if(first_time.hours > second_time.hours)
	{
		return 1;
	}
	else if(first_time.hours < second_time.hours)
	{
		return -1;
	}
	else if(first_time.hours == second_time.hours)
	{
		if(first_time.minutes > second_time.minutes)
		{
			return 1;
		}
		else if(first_time.minutes < second_time.minutes)
		{
			return -1;
		}
		else if(first_time.minutes == second_time.minutes)
		{
			return 0;
		}
	}
	return -2;
}

/*------------------------------------------------------------
| Funcao: add_flight_to_airports
| Argumentos: init_flight -> apontador para o inicio da lista de voos do aeroporto (cidade de partida);
				init_city -> apontador para o início da lista de voos da cidade de chegada;
				flight_data -> informação relativa ao voo;
| Return: Void.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

FLIGHT* add_flight_to_airports(FLIGHT** init_flight, CITY** init_city, INFO_FLIGHT flight_data)
{
	CITY* aux;

	aux = (*init_city);
	while((aux != NULL) && (strcmp(aux->city_name, flight_data.arrival) != 0))
	{
		aux = aux->next;
	}

	aux->next_flight = add_flight(aux->next_flight, flight_data);

	(*init_flight) = add_flight((*init_flight), flight_data);

	return aux->next_flight;
}

/*------------------------------------------------------------
| Funcao: init_connect_flight
| Argumentos: Sem Argumentos.
| Return: Ponto de acesso a uma nova lista que contem os voos com escala.
| Autor: Francisco May e Gustavo Duarte
| Data: 2019/12/18
| Versão: 0.0
--------------------------------------------------------------*/
CONNECT_FLIGHT* init_connect_flight()
{
	return NULL;
}

/*------------------------------------------------------------
| Funcao: add_connect_flight
| Argumentos: init -> apontador para o inicio da lista de voos com escala;
| 			first_flight -> primeiro voo;
			second_flight -> segundo voo;
| Return: O ponto de acesso ao inicio da lista de voos com escala.
| Autor: Francisco May e Gustavo Duarte
| Data: 2019/12/18
| Versão: 0.0
--------------------------------------------------------------*/

CONNECT_FLIGHT* add_connect_flight(CONNECT_FLIGHT* init, FLIGHT first_flight, FLIGHT second_flight, float dist)
{

	CONNECT_FLIGHT* new, *before, *current;

	new = (CONNECT_FLIGHT *)calloc(1, sizeof(CONNECT_FLIGHT));
	if(new == NULL){
		printf("Allocation Error! :-(");
		exit(-1);
	}
	new->first_flight = first_flight;
	new->second_flight = second_flight;
	new->dist = dist;
	new->next = NULL;

	current = init;
	before = NULL;
	while((current != NULL) && (current->dist < new->dist)){					/*Falta a distância para ordenar os voos com escala!!!!!!!!!!!!!!!!!!!!*/

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

void view_connect_flight(CONNECT_FLIGHT* init)
{
		printf("%s %s %s %02d:%02d %s %02d:%02d Dist Between:%f		->		%s %s %s %02d:%02d %s %02d:%02d Dist Between:%f       Total Distance:%f\n", init->first_flight.flight_details.airline_name, init->first_flight.flight_details.flight_code, init->first_flight.flight_details.departure, init->first_flight.flight_details.departure_time.hours, init->first_flight.flight_details.departure_time.minutes, init->first_flight.flight_details.arrival, init->first_flight.flight_details.arrival_time.hours, init->first_flight.flight_details.arrival_time.minutes, init->first_flight.flight_details.dist_bet_airports, init->second_flight.flight_details.airline_name, init->second_flight.flight_details.flight_code, init->second_flight.flight_details.departure, init->second_flight.flight_details.departure_time.hours, init->second_flight.flight_details.departure_time.minutes, init->second_flight.flight_details.arrival, init->second_flight.flight_details.arrival_time.hours, init->second_flight.flight_details.arrival_time.minutes, init->second_flight.flight_details.dist_bet_airports, init->dist);

}

/*------------------------------------------------------------
| Funcao: create_connect_flights
| Argumentos: airports -> apontador para o inicio da lista de aeroportos;
			init -> apontador para o inicio da lista de voos com escala;
			departure_1st_flight[] -> argumento recebido pelo utilizador correspondente à cidade de partida;
			arrival_2nd_flight[] -> argumento recebido pelo utilizador correspondente à cidade de chegada;
| Return: Retorna um apontador para a lista de voos com escala.
| Autor: Francisco May e Gustavo Duarte
| Data: 2019/12/18
| Versão: 0.0
--------------------------------------------------------------*/

CONNECT_FLIGHT* create_connect_flights(AIRPORT* airports, CONNECT_FLIGHT* init, char departure_1st_flight[], char arrival_2nd_flight[])
{
	AIRPORT* aux;
	CITY* aux_city;
	CONNECT_FLIGHT *current;
	FLIGHT dummy;

	strcpy(dummy.flight_details.flight_code, "-----");
	strcpy(dummy.flight_details.departure, "-----");
	strcpy(dummy.flight_details.arrival, "-----");
	strcpy(dummy.flight_details.airline_name, "-----");
	dummy.flight_details.dist_bet_airports = 0;
	dummy.next_flight = NULL;

	aux = airports;
	while(aux != NULL)
	{
		if(strcmp(aux->airport_details.city, departure_1st_flight) != 0)
		{
			while(aux->upcoming_flight != NULL)
			{
				if(strcmp(aux->upcoming_flight->flight_details.arrival, arrival_2nd_flight) == 0)
				{
					init = add_connect_flight(init, dummy, (*aux->upcoming_flight), aux->upcoming_flight->flight_details.dist_bet_airports);
				}

				aux->upcoming_flight = aux->upcoming_flight->next_flight;
			}
		}
		aux = aux->next;
	}
	aux = airports;
	while((aux != NULL) && (strcmp(aux->airport_details.city, departure_1st_flight) != 0))
	{
		aux = aux->next;
	}
	if(aux == NULL)
	{
		printf("ERROR:The departure city does not exist in the Database! :-(\n");
		exit(-1);
	}
	current = init;
	while(current != NULL)
	{
		aux_city = aux->next_city;
		while((aux_city != NULL) && (strcmp(aux_city->city_name, current->second_flight.flight_details.departure) != 0))
		{
			aux_city = aux_city->next;
		}

		if(aux_city == NULL)
		{
			printf("\nERROR:The connecting city does not exist in the Database! :-(\n");
			exit(-1);
		}
		while(aux_city->next_flight != NULL)
		{
			init = add_connect_flight(init, (*aux_city->next_flight), current->second_flight, current->dist + aux_city->next_flight->flight_details.dist_bet_airports);
			aux_city->next_flight = aux_city->next_flight->next_flight;
		}
		current = current->next;
	}
	return init;
}

/*------------------------------------------------------------
| Funcao: remove_dummies
| Argumentos: init -> apontador para o inicio da lista de voos com escala;
| Return: Retorna um apontador para a lista de voos com escala.
| Autor: Francisco May e Gustavo Duarte
| Data: 2019/12/18
| Versão: 0.0
--------------------------------------------------------------*/

CONNECT_FLIGHT* remove_dummies(CONNECT_FLIGHT* init)
{
	CONNECT_FLIGHT *dom, *current, *before;

	current = init;
	before = NULL;
	while(current != NULL)
	{
		if(strcmp(current->first_flight.flight_details.departure, "-----") == 0)
		{
			if(current == init)
			{
				dom = current;
				current = current->next;
				init = dom->next;
				free(dom);
			}
			else
			{
				dom = current;
				current = current->next;
				before->next = dom->next;
				free(dom);
			}
		}
		else
		{
			before = current;
			current = current->next;
		}
	}
	return init;
}