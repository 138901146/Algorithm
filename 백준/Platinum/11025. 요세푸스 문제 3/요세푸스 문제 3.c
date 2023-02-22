#include<stdio.h>

int main(void)
{
	int n, k, josephus=1;

	scanf("%d%d", &n, &k);

	for(int i=1;i<n;i++)
		josephus=(josephus+k-1)%(i+1)+1;

	printf("%d\n", josephus);
	return 0;
}