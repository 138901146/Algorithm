#include<stdio.h>

int main(void)
{
	float temperature[2];

	scanf("%f", &temperature[0]);
	scanf("%f", &temperature[1]);
	for(int i=2;temperature[(i-1)%2]!=999.0;i++)
	{
		printf("%.2f\n", temperature[(i-1)%2]-temperature[i%2]);
		scanf("%f", &temperature[i%2]);
	}

	return 0;
}