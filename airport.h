#ifndef AIRPORT_H
#define AIRPORT_H

#include "city.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coordenates {
	int degree, minutes, seconds;
	char orientation;
} COORD;


typedef struct info_airport
{
	char id_ICAO[dimv];
	char id_IATA[dimv];
	COORD longitude;
	COORD latitude;
	char city[dimv_city];
	int time_zone;
} INFO_AIRPORT;

typedef struct airport {
	INFO_AIRPORT airport_details;
	struct airport* next;
	FLIGHT * upcoming_flight;
	CITY * next_city;
} AIRPORT;

AIRPORT* init_airport();

AIRPORT* add_airport(AIRPORT* init, INFO_AIRPORT airport_data);

void view_airports(AIRPORT* init);



/*In File Read_Files.c*/

AIRPORT* read_airport_file(AIRPORT *airports);

/*In File Read_Files.c*/

#endif /*airport.h*/



