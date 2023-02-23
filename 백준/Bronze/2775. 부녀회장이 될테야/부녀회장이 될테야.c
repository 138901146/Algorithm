#include<stdio.h>

int function(int k,int n)
{
	return k==0?n:n==1?1:function(k,n-1)+function(k-1,n);
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i=0;i<T;i++)
	{
		int k, n;

		scanf("%d", &k);
		scanf("%d", &n);

		printf("%d\n", function(k,n));
	}

	return 0;
}