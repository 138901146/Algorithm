#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, *parent=NULL, A, B, A_count=0, B_count=0, temp;

		scanf("%d", &N);
		parent=(int *)calloc(N+1,sizeof(int));

		for(int n=1;n<N;n++)
		{
			scanf("%d%d", &A, &B);
			parent[B]=A;
		}

		scanf("%d%d", &A, &B);

		temp=A;
		while(parent[temp]!=0)
		{
			A_count++;
			temp=parent[temp];
		}

		temp=B;
		while(parent[temp]!=0)
		{
			B_count++;
			temp=parent[temp];
		}

		if(A_count>B_count)
			for(int a=0;A_count-a>B_count;a++)
				A=parent[A];
		else if(B_count>A_count)
			for(int b=0;B_count-b>A_count;b++)
				B=parent[B];

		while(A!=B)
		{
			A=parent[A];
			B=parent[B];
		}

		printf("%d\n", A);
		free(parent);
	}

	return 0;
}