#include<stdio.h>

int main(void)
{
	int current=0, t;
	char state[4]={'N','E','S','W'};

	for(int i=0;i<10;i++)
	{
		scanf("%d", &t);
		current=(current+t)%4;
	}

	printf("%c\n", state[current]);
	return 0;
}