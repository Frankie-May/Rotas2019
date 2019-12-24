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

#endif /* city.h */
