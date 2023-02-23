#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *P=NULL, sum=0;

	scanf("%d", &N);
	P=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &P[i]);

	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++)
			if(P[i]>P[j])
			{
				int temp=P[i];
				P[i]=P[j];
				P[j]=temp;
			}
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			sum+=P[j];

	printf("%d\n", sum);

	free(P);
	return 0;
}