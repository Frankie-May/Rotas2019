#include "airport.h"


int main(int argc, char * argv[])
{
	AIRPORT *airports, *aux;

	printf("%s %s \n", argv[1], argv[2]);

	airports = init_airport();

	airports = read_airport_file(airports);

	/*printf("\n");
	view_airports(airports);*/
	add_city_to_airports(airports);

	read_routes_file(airports);

	aux = airports;
	while(aux != NULL)
	{
		view_flight(aux->upcoming_flight);
		printf("\n");
		aux = aux->next;
	}

	return 0;
}
