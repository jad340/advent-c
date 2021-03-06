#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isNice(char str[])
{
	int pairs = 0;
	int repeatedChars = 0;

	for(int i = 0; i < strlen(str) - 4; i++)
		for(int j = i + 2; j < strlen(str); j++)
			if(str[j] == str[i] && str[j + 1] == str[i + 1])
				pairs++;

	for(int i = 0; i < strlen(str) - 2; i++)
		if(str[i] == str[i + 2])
			repeatedChars++;

	if(pairs >= 1 && repeatedChars >= 1)
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{
	int count = 0;
	char str[20];

	FILE *input = fopen("input", "r");

	while(fgets(str, sizeof str, input) != NULL)
		if(isNice(str)) count++;

	printf("There are %d nice strings\n", count);

	fclose(input);
	return 0;
}
