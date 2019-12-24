#ifndef FLIGHT_H
#define FLIGHT_H
#define dimv 10
#define dimv_city 12

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct time{
	int hours, minutes;
	char ampm[dimv];
}TIME;

typedef struct flight{
	char flight_code[dimv];
	char departure[dimv_city];
	TIME departure_time;
	char arrival[dimv_city];
	TIME arrival_time;
} FLIGHT;

#endif /* flight.h */
