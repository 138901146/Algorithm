#include<stdio.h>

int main(void)
{
	int M, D, month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}, days=0;

	scanf("%d%d", &D, &M);

	while(--M)
		days+=month[M];
	days+=D-1;

	switch(days%7)
	{
		case 0:
			printf("Thursday\n");
			break;
		case 1:
			printf("Friday\n");
			break;
		case 2:
			printf("Saturday\n");
			break;
		case 3:
			printf("Sunday\n");
			break;
		case 4:
			printf("Monday\n");
			break;
		case 5:
			printf("Tuesday\n");
			break;
		case 6:
			printf("Wednesday\n");
			break;
	}

	return 0;
}