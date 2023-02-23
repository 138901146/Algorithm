#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		int r, e, c;

		scanf("%d %d %d", &r, &e, &c);

		printf("%s\n", r>e-c?"do not advertise":r<e-c?"advertise":"does not matter");
	}

	return 0;
}