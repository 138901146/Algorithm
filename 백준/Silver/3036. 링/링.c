#include<stdio.h>
#include<stdlib.h>

int gcd(int x,int y)
{
	if(x<y)
	{
		int temp=x;
		x=y;
		y=temp;
	}

	while(y!=0)
	{
		int temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

int main(void)
{
	int N, *radius=NULL;

	scanf("%d", &N);
	radius=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d", &radius[i]);

	for(int i=1;i<N;i++)
		printf("%d/%d\n", radius[0]/gcd(radius[0],radius[i]),radius[i]/gcd(radius[0],radius[i]));
	free(radius);
	return 0;
}