#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, *U=NULL;

	scanf("%d", &N);
	U=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &U[n]);

	qsort((void *)U,(size_t)N,sizeof(int),compare);

	for(int k=N-1;k>0;k--)
		for(int x=k-1;x>=0;x--)
		{
			int target=U[k]-U[x], left=0, right=x;

			while(left<right)
			{
				if(U[left]+U[right]<target)
					left++;
				else if(U[left]+U[right]>target)
					right--;
				else
					break;
			}

			if(U[left]+U[right]==target)
			{
				printf("%d\n", U[k]);
				free(U);
				return 0;
			}
		}

	free(U);
	return 0;
}