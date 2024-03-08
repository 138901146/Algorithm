#include<stdio.h>

int arr[2000001]={0};

int main(void)
{
	int N, A;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &A);
		++arr[A+1000000];
	}

	A=-1000000;
	for(int i=0;i<2000001;++i,++A)
		for(int j=0;j<arr[i];++j)
			printf("%d\n", A);

	return 0;
}