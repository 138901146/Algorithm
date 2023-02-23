#include<stdio.h>

int main(void)
{
	int num[7], sum=0, min=100;

	for(int i=0;i<7;i++)
	{
		scanf("%d", &num[i]);

		if(num[i]%2==1)
		{
			sum+=num[i];
			min=num[i]<min?num[i]:min;
		}
	}

	if(sum==0)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, min);

	return 0;
}