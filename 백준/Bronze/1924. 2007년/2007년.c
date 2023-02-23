#include<stdio.h>

int main(void)
{
	int x, y;

	scanf("%d %d", &x, &y);

	for(int i=1;i<x;i++)
		switch(i)
		{
			case 2:
					y+=28;
					break;
			case 4:
			case 6:
			case 9:
			case 11:
					y+=30;
					break;
			default:
					y+=31;
					break;
		}

	switch(y%7)
	{
		case 0:
				printf("SUN\n");
				break;
		case 1:
				printf("MON\n");
				break;
		case 2:
				printf("TUE\n");
				break;
		case 3:
				printf("WED\n");
				break;
		case 4:
				printf("THU\n");
				break;
		case 5:
				printf("FRI\n");
				break;
		case 6:
				printf("SAT\n");
				break;
	}

	return 0;
}