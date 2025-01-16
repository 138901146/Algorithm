#include<stdio.h>

int main(void)
{
	int N, width, height, total=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &width, &height);
		total+=width==136?1000:width==142?5000:width==148?10000:50000;
	}

	printf("%d", total);
	return 0;
}