#include<stdio.h>

int main(void)
{
	int n, rectangle[1001]={1,1,0, };

	scanf("%d", &n);
	for(int i=2;i<=n;i++)
		rectangle[i]=(rectangle[i-1]+rectangle[i-2])%10007;

	printf("%d\n", rectangle[n]);
	return 0;
}