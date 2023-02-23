#include<stdio.h>

int main(void)
{
	int N;
	long long int arr[3];

	scanf("%d", &N);

	for(int n=0;n<3;n++)
		scanf("%lld", &arr[n]);

	if(arr[0]+arr[2]==2*arr[1])
	{
		for(int n=3;n<N;n++)
			scanf("%lld", &arr[2]);
		printf("%lld\n", arr[2]+arr[1]-arr[0]);
	}
	else
	{
		for(int n=3;n<N;n++)
			scanf("%lld", &arr[2]);
		printf("%lld\n", arr[2]*arr[1]/arr[0]);
	}

	return 0;
}