#include<stdio.h>

int arr[7], N, M, NM[7];

void N_M(int m)
{
	if(m==M)
	{
		for(int i=0;i<M;i++)
			printf("%d ", NM[i]);
		printf("\n");
		return;
	}

	for(int i=0;i<N;i++)
	{
		NM[m]=arr[i];
		N_M(m+1);
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);

	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(arr[i]>arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}

	N_M(0);
	return 0;
}