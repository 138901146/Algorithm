#include<stdio.h>

int main(void)
{
	int A, B, sum=0;

	scanf("%d%d", &A, &B);

	for(int i=1,current=1;i<=B;i+=current++)
	{
		for(int count=0;count<current;++count)
			if(A<=i+count && i+count<=B)
				sum+=current;
	}

	printf("%d", sum);
	return 0;
}