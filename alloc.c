#include <stdio.h>
#include <stdlib.h>

int main()
{
	char len_max = 1024;
	char current_size = 0;

	char *pStr = malloc(len_max);
	current_size = len_max;

	if(pStr != NULL)
	{
		int c = EOF;
		unsigned int i = 0;
		while (( c = getchar()) != '\n' && c != EOF)
		{
			pStr[i++]=(char)c;

		if(i == current_size)
		{
			current_size = i+len_max;
			pStr = realloc(pStr, current_size);
		}
	}
	pStr[i] = '\0';
	
	printf("\nLng String value:%s \n\n",pStr);

	free(pStr);
	
	pStr = NULL;
	}
	
	return 0;
}
