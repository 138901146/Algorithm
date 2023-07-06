#include<stdio.h>

int arr[8], N, M, NM[8];

void N_M(int x)
{
	if(x==M)
	{
		for(int i=0;i<M;i++)
			printf("%d ", NM[i]);
		printf("\n");
		return;
	}

	for(int i=0;i<N;i++)
	{
		int count=0;

		for(int j=0;j<x;j++)
			if(NM[j]==arr[i])
			{
				count++;
				break;
			}

		if(count==0)
		{
			NM[x]=arr[i];
			N_M(x+1);
		}
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