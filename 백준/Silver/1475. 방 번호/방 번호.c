#include<stdio.h>

int main(void)
{
	int N, max=0, number[10]={0, };

	scanf("%d", &N);

	number[0]+=N==0;

	while(N>0)
	{
		number[N%10]++;
		N/=10;
	}

	if((number[6]+number[9])%2==0)
		number[6]=number[9]=(number[6]+number[9])/2;
	else
	{
		number[6]+=number[9];
		number[9]=number[6]/2;
		number[6]-=number[9];
	}

	for(int i=0;i<10;i++)
		max=number[i]>max?number[i]:max;

	printf("%d\n", max);

	return 0;
}