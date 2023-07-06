#include<stdio.h>

int arr[20], count=0, N, S;

void partial_array(int index,int sum,int used)
{
	if(index==N)
	{
		count+=sum==S&&used>0;
		return;
	}
	partial_array(index+1,sum+arr[index],used+1);
	partial_array(index+1,sum,used);
}

int main(void)
{
	scanf("%d%d", &N, &S);

	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);

	partial_array(0,0,0);

	printf("%d\n", count);
	return 0;
}