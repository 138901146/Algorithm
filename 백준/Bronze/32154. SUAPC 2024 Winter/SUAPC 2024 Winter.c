#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	switch(N)
	{
		case 1:
			printf("11\nA B C D E F G H J L M");
			break;
		case 2:
		case 3:
			printf("9\nA C E F G H I L M");
			break;
		case 4:
			printf("9\nA B C E F G H L M");
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			printf("8\nA C E F G H L M");
			break;
		case 10:
			printf("8\nA B C F G H L M");
			break;
	}

	return 0;
}