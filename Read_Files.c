/*Read Files!*/

#include "airport.h"

#define LN 1000
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