#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	bool number[2001]={false, };
	int N;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		int temp;

		scanf("%d", &temp);

		number[temp+1000]=true;
	}

	for(int i=0;i<2001;i++)
		if(number[i])
			printf("%d ", i-1000);
	printf("\n");

	return 0;
}