#include<stdio.h>

int count=0, arr[11], N, K;

void find_kth(int n,int index)
{
	if(count>K)
		return;
	else if(n==N)
	{
		count++;
		if(count==K)
		{
			printf("%d", arr[0]);
			for(int i=1;i<index;i++)
				printf("+%d", arr[i]);
			printf("\n");
			count++;
			return;
		}
	}

	for(int i=1;i<=3;i++)
		if(count>=K)
			return;
		else if(n+i<=N)
		{
			arr[index]=i;
			find_kth(n+i,index+1);
		}
}

int main(void)
{
	scanf("%d%d", &N, &K);

	find_kth(0,0);
	if(count<K)
		printf("-1\n");

	return 0;
}