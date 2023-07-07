#include<stdio.h>

int N, numbers[80], found=0;

void good_numbers(int index)
{
	if(found)
		return;

	for(int i=1;(i<<1)<=index;i++)
	{
		int same=1;

		for(int j=1;j<=i;j++)
			if(numbers[index-j]!=numbers[index-i-j])
			{
				same=0;
				break;
			}

		if(same)
			return;
	}

	if(index==N)
	{
		for(int i=0;i<index;i++)
			printf("%d", numbers[i]);
		printf("\n");
		found=1;
		return;
	}
	else
		for(int i=1;i<=3;i++)
		{
			numbers[index]=i;
			good_numbers(index+1);
		}
}

int main(void)
{
	scanf("%d", &N);
	good_numbers(0);
	return 0;
}