#ifndef FLIGHT_H
#define FLIGHT_H
#define dimv 10
#define dimv_city 12
#define dimv_airline 30

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct time{
	int hours, minutes;
}TIME;

typedef struct {
	char flight_code[dimv];
	char departure[dimv_city];
	TIME departure_time;
	char arrival[dimv_city];
	TIME arrival_time;
	char airline_name[dimv_airline];
	float dist_bet_airports;
}INFO_FLIGHT;

typedef struct flight{
	INFO_FLIGHT flight_details;
	struct flight *next_flight;
} FLIGHT;

typedef struct connect_flight{
	FLIGHT first_flight;
	FLIGHT second_flight;
	float dist;
	struct connect_flight *next;
} CONNECT_FLIGHT;


FLIGHT* add_flight(FLIGHT *init, INFO_FLIGHT flight_data);

FLIGHT* add_flight_invert(FLIGHT *init, INFO_FLIGHT flight_data);

void view_flight(FLIGHT* init);

int time_comparison(TIME first_time,TIME second_time);

CONNECT_FLIGHT* init_connect_flight();

CONNECT_FLIGHT* add_connect_flight(CONNECT_FLIGHT* init, FLIGHT first_flight, FLIGHT second_flight, float dist);

void view_connect_flight(CONNECT_FLIGHT* init);

CONNECT_FLIGHT* remove_dummies(CONNECT_FLIGHT* init);


#endif /* flight.h */
