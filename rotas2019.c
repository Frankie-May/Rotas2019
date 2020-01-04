#include "airport.h"

int main(int argc, char * argv[]){
	/*printf("%s %s \n", argv[1], argv[2]);*/

	char *test;
	FILE* fp;

	strcpy(test, "Ficheiro_dos_aeroportos.txt");
	fp = fopen(test , "r");
	if (fp == NULL)
	{
		printf("ERROR: Error opening file: %s! :-(\n", test);
		return -1;
	}

	fclose(fp);
	fprintf(stdout, "%s\n", "End of File! :-)");

	return 0;
}
