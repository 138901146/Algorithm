#include<stdio.h>

int main(void)
{
	int A, B, C, D, max=0;
	float value[4];

	scanf("%d %d", &A, &B);
	scanf("%d %d", &C, &D);

	value[0]=(float)A/C+(float)B/D;
	value[1]=(float)C/D+(float)A/B;
	value[2]=(float)D/B+(float)C/A;
	value[3]=(float)B/A+(float)D/C;

	for(int i=1;i<4;i++)
		max=value[i]>value[max]?i:max;

	printf("%d\n", max);
	return 0;
}