#include<stdio.h>

int main(void)
{
	int y, m, d;

	scanf("%d-%d-%d", &y, &m, &d);

	if(m<9)
		printf("GOOD");
	else
	{
		if(m==9 && d<=16)
			printf("GOOD");
		else
			printf("TOO LATE");
	}

	return 0;
}