#ifndef AIRPORT_H
#define AIRPORT_H
#define LN 1000
#define HOUR_MARGIN 0
#define MINUTE_MARGIN 0
#define PI 3.14159265358979323846

#include "city.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

float airport_distance(AIRPORT first_airport, AIRPORT second_airport);

float dms_to_lat(COORD coord);

float dms_to_long(COORD coord);


/*In File Read_Files.c*/

AIRPORT* read_airport_file(AIRPORT *airports);

void read_routes_file(AIRPORT *airports);

/*In File Read_Files.c*/


/*In File city.h*/

void add_city_to_airports(AIRPORT* init);

/*In File city.h*/

/*In File flight.c*/

CONNECT_FLIGHT* create_connect_flights(AIRPORT* airports, CONNECT_FLIGHT* init, char departure_1st_flight[], char arrival_2nd_flight[]);

/*In File flight.c*/

#endif /*airport.h*/



