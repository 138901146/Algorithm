#include<stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{
		int binary[24]={0, }, decimal=0;

		for(int b=0;b<24;b++)
			scanf("%1d", &binary[b]);

		for(int p=0, power=1;p<24;p++,power*=2)
			decimal+=power*binary[23-p];

		printf("%d\n", decimal);
	}

	return 0;
}