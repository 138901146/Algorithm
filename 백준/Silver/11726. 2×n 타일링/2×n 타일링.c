#include<stdio.h>

int main(void)
{
	int n, rectangle[1001]={0,1,2,0,};

	scanf("%d", &n);

	for(int i=3;i<=n;i++)
		rectangle[i]=(rectangle[i-1]+rectangle[i-2])%10007;

	printf("%d\n", rectangle[n]);
	return 0;
}