#include<stdio.h>

int main(void)
{
	int m, d;

	scanf("%d", &m);
	scanf("%d", &d);

	if(m<2)
		printf("Before");
	else if(2<m)
		printf("After");
	else
		if(d<18)
			printf("Before");
		else if(18<d)
			printf("After");

		else
			printf("Special");

	return 0;
}