#ifndef CITY_H
#define CITY_H

#include "flight.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct city{
	char city_name[dimv_city];
	struct city* next;
	FLIGHT * next_flight;
}CITY;


CITY* add_city(CITY *init, char city_name[]);

void view_city(CITY* init);

/*In File flight.c*/

void add_flight_to_airports(FLIGHT* init_flight, CITY* init_city, INFO_FLIGHT flight_data);

/*In File flight.c*/

#endif /* city.h */
