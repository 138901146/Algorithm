#include<stdio.h>

int main(void)
{
	int lv;
	char judge;

	scanf("%d %c", &lv, &judge);

	switch(judge)
	{
		case 'm':
			printf("0");
			break;
		case 'b':
			printf("%d", lv*200);
			break;
		case 'c':
			printf("%d", lv*400);
			break;
		case 'g':
			printf("%d", lv*600);
			break;
		case 'p':
			printf("%d", lv*1000);
			break;
	}

	return 0;
}