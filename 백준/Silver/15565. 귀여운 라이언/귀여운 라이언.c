#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, doll, *lion=NULL, size=0, min=10000000;

	scanf("%d%d", &N, &K);
	lion=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &doll);

		if(doll==1)
		{
			lion[size++]=n;

			if(size>=K)
				min=n-lion[size-K]<min?n-lion[size-K]:min;
		}
	}

	printf("%d\n", min!=10000000?min+1:-1);
	free(lion);
	return 0;
}