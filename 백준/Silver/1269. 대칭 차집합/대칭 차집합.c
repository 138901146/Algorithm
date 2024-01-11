#include<stdio.h>

int flag[3333334]={0};

int main(void)
{
	int A, B, element, total, count=0;

	scanf("%d%d", &A, &B);
	total=A+B;

	while(A--)
	{
		scanf("%d", &element);
		flag[element/30]|=1<<element%30;
	}

	while(B--)
	{
		scanf("%d", &element);
		count+=(flag[element/30]&1<<element%30)!=0;
	}

	printf("%d", total-(count<<1));
	return 0;
}