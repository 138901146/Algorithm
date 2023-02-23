#include<stdio.h>

int main(void)
{
	int n, T, work, sum=0, count;

	scanf("%d %d", &n, &T);

	for(count=0;count<n;count++)
	{
		scanf("%d", &work);
		sum+=work;
		if(sum>T)
			break;
	}

	printf("%d\n", count);
	return 0;
}