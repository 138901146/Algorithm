#include<stdio.h>

int main(void)
{
	int A, B, C, time[101]={0, }, start, end, price=0;

	scanf("%d %d %d", &A, &B, &C);

	for(int i=0;i<3;i++)
	{
		scanf("%d %d", &start, &end);

		for(int t=start;t<end;t++)
			time[t]++;
	}

	for(int i=1;i<101;i++)
		price+=time[i]==1?A:time[i]==2?2*B:time[i]==3?3*C:0;

	printf("%d\n", price);
	return 0;
}