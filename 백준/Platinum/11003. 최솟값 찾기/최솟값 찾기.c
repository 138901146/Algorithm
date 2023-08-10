#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, L, *A=NULL, *queue=NULL, front=0, rear=0;

	scanf("%d%d", &N, &L);
	A=(int *)malloc(N*sizeof(int));
	queue=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
	{
		scanf("%d", &A[i]);

		while(front<rear && A[queue[rear-1]]>=A[i])
			rear--;
		queue[rear++]=i;

		if(queue[front]<=i-L)
			front++;

		printf("%d ", A[queue[front]]);
	}

	free(A);
	free(queue);
	return 0;
}
