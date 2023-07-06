#include<stdio.h>

int N, arr[8], max=0, order[8];

int abs(int x)
{
	return x<0?-x:x;
}

void find_max(int index)
{
	if(index==N)
	{
		int sum=0;

		for(int i=1;i<N;i++)
			sum+=abs(arr[order[i]]-arr[order[i-1]]);
		max=sum>max?sum:max;
		return;
	}

	int check[8]={0, };
	for(int i=0;i<index;i++)
		check[order[i]]=1;

	for(int i=0;i<N;i++)
		if(!check[i])
		{
			order[index]=i;
			find_max(index+1);
		}
}

int main(void)
{
	scanf("%d", &N);
	for(int n=0;n<N;n++)
		scanf("%d", &arr[n]);

	find_max(0);

	printf("%d\n", max);
	return 0;
}