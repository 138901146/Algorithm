#include<stdio.h>
#include<stdbool.h>

int N, arr[8];

void factorial(int index)
{
	if(index==N)
	{
		for(int i=0;i<N;i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	bool check[8]={false, };

	for(int i=0;i<index;i++)
		check[arr[i]-1]=true;

	for(int i=0;i<N;i++)
		if(!check[i])
		{
			arr[index]=i+1;
			factorial(index+1);
		}
}

int main(void)
{
	scanf("%d", &N);
	factorial(0);
	return 0;
}