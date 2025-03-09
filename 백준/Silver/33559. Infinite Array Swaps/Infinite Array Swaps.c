#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

int main(void)
{
	int N, *A=NULL, *B=NULL, *Ap=NULL, *Bp=NULL, A_left=0, B_left=0, Ap_left=0, Bp_left=0, Ap_right, Bp_right, count=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(N*sizeof(int));
	Ap=(int *)malloc(N*sizeof(int));
	Bp=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);
	for(int i=0;i<N;++i)
		scanf("%d", &B[i]);
	qsort((void *)A,(size_t)N,sizeof(int),compare);
	qsort((void *)B,(size_t)N,sizeof(int),compare);

	Ap_right=Bp_right=N-1;
	while(A_left<N || B_left<N)
	{
		if(A_left==N)
			Bp[Bp_left++]=B[B_left++];
		else if(B_left==N)
			Ap[Ap_left++]=A[A_left++];
		else if(A[A_left]<B[B_left])
			while(A_left<N && A[A_left]<B[B_left])
				Ap[Ap_right--]=A[A_left++];
		else if(B[B_left]<A[A_left])
			while(B_left<N && B[B_left]<A[A_left])
				Bp[Bp_right--]=B[B_left++];
		else
			while(A_left<N && B_left<N && A[A_left]==B[B_left])
			{
				Ap[Ap_left++]=Bp[Bp_left++]=A[A_left++];
				++B_left;
			}
	}

	while(count<N && Ap[count]==Bp[count])
		++count;

	printf("%d\n", count);
	for(int i=0;i<N;++i)
		printf("%d ", Ap[i]);
	printf("\n");
	for(int i=0;i<N;++i)
		printf("%d ", Bp[i]);
	free(A);
	free(B);
	free(Ap);
	free(Bp);
	return 0;
}