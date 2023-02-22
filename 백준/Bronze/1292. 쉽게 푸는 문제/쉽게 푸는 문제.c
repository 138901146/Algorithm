#include<stdio.h>

int main(void)
{
	int A, B, current=1, count=0, sum=0;

	scanf("%d %d", &A, &B);

	for(int i=1;i<=B;i++)
	{
		if(i>=A)
			sum+=current;
		count++;
		if(count==current)
		{
			current++;
			count=0;
		}
	}

	printf("%d\n", sum);
	return 0;
}