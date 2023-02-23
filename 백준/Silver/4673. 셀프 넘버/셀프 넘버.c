#include<stdio.h>

int d(int n)
{
	int k=n;

	while(n>0)
	{
		k+=n%10;
		n/=10;
	}

	return k;
}

int main(void)
{
	int N=1, arr[10001]={0, };

	while(d(N)<=10000)
		arr[d(N++)]++;

	for(int i=1;i<=9993;i++)
		if(arr[i]==0)
			printf("%d\n", i);

	return 0;
}