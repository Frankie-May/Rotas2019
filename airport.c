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


/*------------------------------------------------------------
| Funcao: airport_distance
| Argumentos: first_airport -> aeroporto da cidade de partida;
|				second_airport -> aeroporto da cidade de chegada;
| Return: Retorna a distância entre os dois aeroportos.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

float airport_distance(AIRPORT first_airport, AIRPORT second_airport)
{
	int R0 = 6371, R;
	float latitude_1, longitude_1, latitude_2, longitude_2;
	float xa, ya, za, xb, yb, zb;
	float angle;

	R = R0 + 10;

	latitude_1 = (PI/180) * dms_to_lat(first_airport.airport_details.longitude);

	longitude_1 = (PI/180) * dms_to_long(first_airport.airport_details.latitude);

	latitude_2 = (PI/180) * dms_to_lat(second_airport.airport_details.longitude);

	longitude_2 = (PI/180) * dms_to_long(second_airport.airport_details.latitude);

	xa = R * cos(latitude_1) * cos(longitude_1);
	ya = R * cos(latitude_1) * sin(longitude_1);
	za = R * sin(latitude_1);

	xb = R * cos(latitude_2) * cos(longitude_2);
	yb = R * cos(latitude_2) * sin(longitude_2);
	zb = R * sin(latitude_2);

	angle = acos((xa*xb + ya*yb + za*zb)/(sqrt(pow(xa,2) + pow(ya,2) + pow(za,2)) * sqrt(pow(xb,2) + pow(yb,2) + pow(zb,2))));

	return angle * R;
}

/*------------------------------------------------------------
| Funcao: dms_to_lat
| Argumentos: coord -> coordenada em dms;
| Return: latitude correspondente.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

float dms_to_lat(COORD coord)
{
	if(coord.orientation == 'N')
	{
		return coord.degree + coord.minutes/60.0 + coord.seconds/3600.0;
	}
	else if(coord.orientation == 'S')
	{
		return -(coord.degree + coord.minutes/60.0 + coord.seconds/3600.0);
	}
	return -1;
}

/*------------------------------------------------------------
| Funcao: dms_to_long
| Argumentos: coord -> coordenada em dms;
| Return: longitude correspondente.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/08
| Versão: 0.0
--------------------------------------------------------------*/

float dms_to_long(COORD coord)
{
	if(coord.orientation == 'E')
	{
		return coord.degree + coord.minutes/60.0 + coord.seconds/3600.0;
	}
	else if(coord.orientation == 'W')
	{
		return -(coord.degree + coord.minutes/60.0 + coord.seconds/3600.0);
	}
	return -1;
}