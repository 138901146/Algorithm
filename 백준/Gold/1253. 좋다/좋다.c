#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, *A=NULL, count=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);

	qsort((void *)A,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;i++)
	{
		bool good=false;

		for(int j=0;j<N;j++)
		{
			if(i==j)
				continue;
			int left=0, right=N-1, mid;

			while(left<right)
			{
				mid=(left+right)/2;
				if(A[mid]+A[j]==A[i])
					break;
				else if(A[mid]+A[j]<A[i])
					left=mid+1;
				else
					right=mid-1;
			}
			mid=(left+right)/2;

			if(A[mid]+A[j]==A[i])
			{
				if(mid!=i && mid!=j)
					good=true;
				else
				{
					left=right=mid;
					while(left>=0 && A[left]==A[mid])
						left--;
					while(right<N && A[right]==A[mid])
						right++;
					for(int k=left+1;k<right;k++)
						if(i!=k && j!=k)
						{
							good=true;
							break;
						}
				}
			}

			if(good)
				break;
		}

		count+=good;
	}

	printf("%d\n", count);
	free(A);
	return 0;
}