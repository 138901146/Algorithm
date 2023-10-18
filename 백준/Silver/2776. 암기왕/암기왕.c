#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, M, *X=NULL, number;

		scanf("%d", &N);
		X=(int *)malloc(N*sizeof(int));

		for(int n=0;n<N;++n)
			scanf("%d", &X[n]);
		qsort((void *)X,(size_t)N,sizeof(int),compare);

		scanf("%d", &M);

		while(M--)
		{
			int left=0, right=N-1, mid;

			scanf("%d", &number);

			if(number<X[left] || number>X[right])
			{
				printf("0\n");
				continue;
			}

			while(left<=right)
			{
				mid=(left+right)>>1;

				if(X[mid]<number)
					left=mid+1;
				else if(X[mid]>number)
					right=mid-1;
				else
					break;
			}

			printf("%d\n", X[mid]==number);
		}

		free(X);
	}

	return 0;
}