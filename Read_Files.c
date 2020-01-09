/*Read Files!*/

#include "airport.h"

/*------------------------------------------------------------
| Funcao: read_airport_file
| Argumentos: airports -> apontador para uma lista composta pelos vários aeroportos.
| Return: Ponto de acesso à lista de aeroportos.
| Autor: Francisco May
| Data: 2020/01/07
| Versão: 0.1
--------------------------------------------------------------*/

AIRPORT* read_airport_file(AIRPORT *airports)
{
	char* aux;
	int verify_conv;
	char line[LN];
	INFO_AIRPORT airport_details;

	char airport_file[30] = "Ficheiro_dos_aeroportos.txt";
	FILE* fp;

	fp = fopen(airport_file , "r");
	if (fp == NULL)
	{
		printf("ERROR: Error opening file: %s! :-(\n", airport_file);
		exit(-1);
	}

	aux = fgets(line, LN, fp);
	if (aux == NULL)
	{
		printf("ERROR:File %s is empty! :-(\n", airport_file);
		exit(-1);
	}
	do{
		verify_conv = sscanf(line, "%s %s %d %d %d %c %d %d %d %c %s %d", airport_details.id_ICAO, airport_details.id_IATA, &airport_details.longitude.degree, &airport_details.longitude.minutes, &airport_details.longitude.seconds, &airport_details.longitude.orientation, &airport_details.latitude.degree, &airport_details.latitude.minutes, &airport_details.latitude.seconds, &airport_details.latitude.orientation, airport_details.city, &airport_details.time_zone);
		if (verify_conv != 12)
		{
			fprintf(stdout, "ERROR:Conversion error in File %s! :-(\n", airport_file);
		}

		airports = add_airport(airports, airport_details);

		aux = fgets(line, LN, fp);
		while ((strcmp(line, "\n") == 0) && (aux != NULL))
		{
			aux = fgets(line, LN, fp);
		}
	} while (aux != NULL);

	fclose(fp);
	fprintf(stdout, "End of File %s! :-)\n", airport_file);

	return airports;
}

/*------------------------------------------------------------
| Funcao: read_routes_file
| Argumentos: airports -> apontador para uma lista composta pelos vários aeroportos.
| Return: Void.
| Autor: Francisco May e Gustavo Duarte
| Data: 2020/01/07
| Versão: 0.1
--------------------------------------------------------------*/

void read_routes_file(AIRPORT *airports)
{
	char* aux;
	AIRPORT* aux_airports;
	int verify_conv_1, verify_conv_2;
	char line[LN], airline[dimv_airline];
	INFO_FLIGHT flight_details;

	char routes_file[30] = "Ficheiro_de_rotas.txt";
	FILE* fp;

	fp = fopen(routes_file , "r");
	if (fp == NULL)
	{
		printf("ERROR: Error opening file: %s! :-(\n", routes_file);
		exit(-1);
	}

	aux = fgets(line, LN, fp);
	if (aux == NULL)
	{
		printf("ERROR:File %s is empty! :-(\n", routes_file);
		exit(-1);
	}
	do{
		verify_conv_1 = sscanf(line, "AIRLINE: %s", airline);
		if(verify_conv_1 != 1)
		{
			fprintf(stdout, "ERROR:Conversion error in File %s, airline identification! :-(\n", routes_file);
		}
		aux = fgets(line, LN, fp);
		do{
			verify_conv_2 = sscanf(line, "%s %s %d:%d %s %d:%d", flight_details.flight_code, flight_details.departure, &flight_details.departure_time.hours, &flight_details.departure_time.minutes, flight_details.arrival, &flight_details.arrival_time.hours, &flight_details.arrival_time.minutes);
			if (verify_conv_2 != 7)
			{	
				fprintf(stdout, "ERROR:Conversion error in File %s! :-(\n", routes_file);
			}
			printf("........%s %s %d:%d %s %d:%d\n", flight_details.flight_code, flight_details.departure, flight_details.departure_time.hours, flight_details.departure_time.minutes, flight_details.arrival, flight_details.arrival_time.hours, flight_details.arrival_time.minutes);
			fflush(stdout);

			strcpy(flight_details.airline_name, airline);


			printf("Seeng if it reaches here!!!!!!\n");
			aux_airports = airports;
			while((aux_airports != NULL) && (strcmp(aux_airports->airport_details.city, flight_details.departure) != 0))
			{
				printf("%s\n", aux_airports->airport_details.city);
				printf("______________________%s\n", flight_details.departure);
				aux_airports = aux_airports->next;
			}

			printf("See if it reaches this point!!!!!!!!!!!!\n");
			fflush(stdout);
			printf("%p\n", (void*)aux_airports);
			add_flight_to_airports(aux_airports->upcoming_flight, aux_airports->next_city, flight_details);
			printf("Something!\n");
			fflush(stdout);

			aux = fgets(line, LN, fp);
		} while ((strcmp(line, "\n") != 0) && (aux != NULL));
		aux = fgets(line, LN, fp);
	} while (aux != NULL);

	fclose(fp);
	fprintf(stdout, "End of File %s! :-)\n", routes_file);
}
