#include<stdio.h>

int main(void)
{
	long long int N;
	int arr[11];

	for(int i=0;i<11;i++)
		arr[i]=-1;

	scanf("%lld", &N);

	for(int i=0;N>0;i++)
	{
		arr[i]=N%10;
		N/=10;
	}

	for(int i=0;arr[i]!=-1;i++)
		for(int j=i+1;arr[j]!=-1;j++)
			if(arr[i]<arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}

	N=0;

	for(int i=0;arr[i]!=-1;i++)
	{
		N*=10;
		N+=arr[i];
	}

	printf("%lld\n", N);

	return 0;
}