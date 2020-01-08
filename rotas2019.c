#include "airport.h"


int main(int argc, char * argv[])
{
	AIRPORT *airports;

	printf("%s %s \n", argv[1], argv[2]);

	airports = init_airport();

	airports = read_airport_file(airports);

	printf("\n");
	view_airports(airports);

	return 0;
}
