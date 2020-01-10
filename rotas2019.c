#include "airport.h"


int main(int argc, char * argv[])
{
	AIRPORT *airports, *aux;
	CITY *aux_city;
	CONNECT_FLIGHT *flights, *aux_flight;
	FLIGHT *flight_invert;
	TIME aux_time;
	int dist;

	if(strcmp(argv[1], "rota2019") != 0)
	{
		printf("ERROR:The command inserted is invalid! :-(\n");
		return -1;
	}

	/*--------------------------------------------------Construir a lista----------------------------*/
	airports = init_airport();

	airports = read_airport_file(airports);

	add_city_to_airports(airports);

	read_routes_file(airports);
	/*--------------------------------------------------Construir a lista----------------------------*/

	
	/*-------------------------Comandos------------------------------------*/
	if(strcmp(argv[2], "-aeroportos") == 0)
	{
		printf("\n          AIRPORTS     \n\n");
		view_airports(airports);
	}
	else if(strcmp(argv[2], "-voos") == 0)
	{
		printf("\n          Flights     \n\n");
		aux = airports;
		while(aux != NULL)
		{
			view_flight(aux->upcoming_flight);
			printf("\n");
			aux = aux->next;
		}
	}
	else if((strcmp(argv[4], "-L") == 0) && (strcmp(argv[5], "0") == 0) && (argc == 6))
	{
		aux = airports;
		while((aux != NULL) && (strcmp(argv[2], aux->airport_details.city) != 0))
		{
			aux = aux->next;
		}
		if(aux == NULL)
		{
			printf("\nERROR:The departure city does not exist in the Database! :-(\n");
			return -1;
		}
		aux_city = aux->next_city;
		while((aux_city != NULL) && (strcmp(argv[3], aux_city->city_name) != 0))
		{
			aux_city = aux_city->next;
		}
		if(aux_city == NULL)
		{
			printf("\nERROR:The arrival city does not exist in the Database! :-(\n");
			return -1;
		}
		if(aux_city->next_flight == NULL)
		{
			printf("\nThe Route you wish to take does not exist! :-(\n");
			return -1;
		}
		printf("\n          Flights     \n\n");
		view_flight(aux_city->next_flight);
	}
	else if((strcmp(argv[4], "-L") == 0) && (strcmp(argv[5], "0") == 0) && (strcmp(argv[6], "-TC") == 0))
	{
		aux = airports;
		while((aux != NULL) && (strcmp(argv[2], aux->airport_details.city) != 0))
		{
			aux = aux->next;
		}
		if(aux == NULL)
		{
			printf("\nERROR:The departure city does not exist in the Database! :-(\n");
			return -1;
		}
		aux_city = aux->next_city;
		while((aux_city != NULL) && (strcmp(argv[3], aux_city->city_name) != 0))
		{
			aux_city = aux_city->next;
		}
		if(aux_city == NULL)
		{
			printf("\nERROR:The arrival city does not exist in the Database! :-(\n");
			return -1;
		}
		if(aux_city->next_flight == NULL)
		{
			printf("\nThe Route you wish to take does not exist! :-(\n");
			return -1;
		}
		printf("\n          Flights     \n\n");
		view_flight(aux_city->next_flight);
	}
	else if((strcmp(argv[4], "-L") == 0) && (strcmp(argv[5], "0") == 0) && (strcmp(argv[6], "-TD") == 0))
	{
		aux = airports;
		while((aux != NULL) && (strcmp(argv[2], aux->airport_details.city) != 0))
		{
			aux = aux->next;
		}
		if(aux == NULL)
		{
			printf("\nERROR:The departure city does not exist in the Database! :-(\n");
			return -1;
		}
		aux_city = aux->next_city;
		while((aux_city != NULL) && (strcmp(argv[3], aux_city->city_name) != 0))
		{
			aux_city = aux_city->next;
		}
		if(aux_city == NULL)
		{
			printf("\nERROR:The arrival city does not exist in the Database! :-(\n");
			return -1;
		}
		if(aux_city->next_flight == NULL)
		{
			printf("\nThe Route you wish to take does not exist! :-(\n");
			return -1;
		}
		flight_invert = NULL;
		while(aux_city->next_flight != NULL)
		{
			flight_invert = add_flight_invert(flight_invert, aux_city->next_flight->flight_details);
			aux_city->next_flight = aux_city->next_flight->next_flight;
		}
		printf("\n          Flights     \n\n");
		view_flight(flight_invert);
	}
	else if((strcmp(argv[4], "-L") == 0) && (strcmp(argv[5], "1") == 0))
	{
		flights = init_connect_flight();

		flights = create_connect_flights(airports, flights, argv[2], argv[3]);

		flights = remove_dummies(flights);

		if(argc == 6)
		{
			printf("\n          Flights     \n\n");
			aux_flight = flights;
			while(aux_flight != NULL)
			{
				view_connect_flight(aux_flight);
				aux_flight = aux_flight->next;
			}
		}
		else if((strcmp(argv[6], "-TC") == 0) && (argc == 7))
		{
			printf("\n          Flights     \n\n");
			aux_flight = flights;
			while(aux_flight != NULL)
			{
				aux_time.hours = aux_flight->first_flight.flight_details.arrival_time.hours + HOUR_MARGIN;
				aux_time.minutes = aux_flight->first_flight.flight_details.arrival_time.minutes + MINUTE_MARGIN;
				if(time_comparison(aux_time, aux_flight->second_flight.flight_details.departure_time) == -1)
				{
					view_connect_flight(aux_flight);
				}
				aux_flight = aux_flight->next;
			}
		}
		else if((strcmp(argv[7], "-D") == 0))
		{
			dist = 0;
			printf("\n          Flights     \n\n");
			aux_flight = flights;
			while((aux_flight != NULL) && (dist == 0))
			{
				aux_time.hours = aux_flight->first_flight.flight_details.arrival_time.hours + HOUR_MARGIN;
				aux_time.minutes = aux_flight->first_flight.flight_details.arrival_time.minutes + MINUTE_MARGIN;
				if(time_comparison(aux_time, aux_flight->second_flight.flight_details.departure_time) == -1)
				{
					view_connect_flight(aux_flight);
					dist = 1;
				}
				aux_flight = aux_flight->next;
			}
		}
	}
	else
	{
		printf("\nERROR:The second command inserted is invalid! :-(\n");
		return -1;
	}

	return 0;
}
