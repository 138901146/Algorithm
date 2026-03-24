#include<stdio.h>

int main(void)
{
	char subject;

	scanf("%c", &subject);

	switch(subject)
	{
		case 'F':
			printf("Foundation");
			break;
		case 'C':
			printf("Claves");
			break;
		case 'V':
			printf("Veritas");
			break;
		case 'E':
			printf("Exploration");
			break;
	}

	return 0;
}