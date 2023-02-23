#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int partition(int list[],int left,int right)
{
	int pivot=list[left], temp, low=left, high=right+1;

	do
	{
		do
			low++;
		while(low<=right&&list[low]<pivot);
		do
			high--;
		while(high>=left&&list[high]>pivot);

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
	int N, *list=NULL;

	scanf("%d", &N);

	list=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", list+i);

	quick_sort(list,0,N-1);

	for(int i=0;i<N;i++)
		printf("%d\n", *(list+i));

	free(list);
	return 0;

}