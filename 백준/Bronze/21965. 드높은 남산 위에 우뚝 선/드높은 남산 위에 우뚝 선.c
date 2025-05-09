#include<stdio.h>

int main(void)
{
	int N, A[2]={0}, previous=1, current=0, peak=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &A[current]);

		if(A[current]==A[previous])
		{
			printf("NO");
			return 0;
		}

		if(peak)
		{
			if(A[previous]<A[current])
			{
				printf("NO");
				return 0;
			}
		}
		else if(A[current]<A[previous])
			peak=1;

		current^=1;
		previous^=1;
	}

	printf("YES");
	return 0;
}