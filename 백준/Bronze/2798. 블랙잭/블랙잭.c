#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, current=0, *card=NULL;

	scanf("%d %d", &N, &M);
	card=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &card[i]);

	for(int i=0;i<N-2;i++)
		for(int j=i+1;j<N-1;j++)
			for(int k=j+1;k<N;k++)
				if(card[i]+card[j]+card[k]<=M && card[i]+card[j]+card[k]>current)
					current=card[i]+card[j]+card[k];

	printf("%d\n", current);

	free(card);
	return 0;
}