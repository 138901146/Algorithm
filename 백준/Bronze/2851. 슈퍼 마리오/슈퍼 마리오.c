#include<stdio.h>

int abs(int N)
{
	return N>=0?N:-N;
}

int main(void)
{
	int score[10], near=0, sum=0;

	for(int i=0;i<10;i++)
	{
		scanf("%d", &score[i]);

		sum+=score[i];
		near=abs(sum-100)<=abs(near-100)?sum:near;
	}

	printf("%d\n", near);

	return 0;
}