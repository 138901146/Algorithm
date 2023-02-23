#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

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
	int N, *colonnade=NULL, gcd_num;

	scanf("%d", &N);
	colonnade=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &colonnade[n]);
	qsort((void *)colonnade,(size_t)N,sizeof(int),compare);

	gcd_num=gcd(colonnade[1]-colonnade[0],colonnade[2]-colonnade[1]);
	for(int i=3;i<N;i++)
		gcd_num=gcd(gcd_num,colonnade[i]-colonnade[i-1]);

	printf("%d\n", (colonnade[N-1]-colonnade[0])/gcd_num-N+1);
	free(colonnade);
	return 0;
}