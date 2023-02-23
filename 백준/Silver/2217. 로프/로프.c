#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y,z) ((z)=(x), (x)=(y), (y)=(z))

int partition(int list[],int left,int right)
{
	int pivot=list[left], low=left, high=right+1, temp;

	do
	{
		do
			low++;
		while(low<=high && list[low]<pivot);
		do
			high--;
		while(high>=left && list[high]>pivot);

		if(low<high)
			SWAP(list[low],list[high],temp);
	}
	while(low<high);

	SWAP(list[left],list[high],temp);

	return high;
}

void quick_sort(int list[],int left,int right)
{
	if(left<right)
	{
		int q=partition(list,left,right);
		quick_sort(list,left,q-1);
		quick_sort(list,q+1,right);
	}
}

int main(void)
{
	int N, max=0, *rope=NULL;

	scanf("%d", &N);
	rope=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &rope[i]);

	quick_sort(rope,0,N-1);

	for(int i=0;i<N;i++)
		max=(N-i)*rope[i]>max?(N-i)*rope[i]:max;

	printf("%d\n", max);

	free(rope);
	return 0;
}