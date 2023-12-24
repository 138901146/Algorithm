#include<stdio.h>

int main(void)
{
	int N, arr[50], max=0;

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		scanf("%d", &arr[n]);

	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
			if(arr[i]>arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}

	for(int i=0;i<N;++i)
	{
		int j=i+1;

		while(j<N && arr[j]<arr[i]+5)
			++j;

		max=j-i>max?j-i:max;
	}

	printf("%d", 5-max);
	return 0;
}