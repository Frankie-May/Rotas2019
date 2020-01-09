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
}INFO_FLIGHT;

typedef struct flight{
	INFO_FLIGHT flight_details;
	struct flight *next_flight;
} FLIGHT;

FLIGHT* add_flight(FLIGHT *init, INFO_FLIGHT flight_data);

void view_flight(FLIGHT* init);

int time_comparison(TIME first_time,TIME second_time);


#endif /* flight.h */
