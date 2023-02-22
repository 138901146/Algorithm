#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, element, current=0, count=0;
	bool *queue=NULL;

	scanf("%d%d", &N, &M);
	queue=(bool *)malloc(N*sizeof(bool));

	for(int n=0;n<N;n++)
		queue[n]=true;

	for(int m=0;m<M;m++)
	{
		int left=0, right=0;
		scanf("%d", &element);
		element--;

		if(element<current)
		{
			for(int k=current;k>element;k--)
				right+=queue[k];
			for(int k=0;k<element;k++)
				left+=queue[k];
			for(int k=current;k<N;k++)
				left+=queue[k];
		}
		else if(element>current)
		{
			for(int k=current;k<element;k++)
				right+=queue[k];
			for(int k=element;k<N;k++)
				left+=queue[k];
			for(int k=0;k<current;k++)
				left+=queue[k];
		}

		count+=left<right?left:right;
		queue[element]=false;
		current=element;
		while(!queue[current] && m!=N-1)
		{
			current++;
			current%=N;
		}
	}

	printf("%d\n", count);
	free(queue);
	return 0;
}