#include<stdio.h>

int main(void)
{
	int N, student, apple, sum=0;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%d %d", &student, &apple);
		sum+=apple%student;
	}

	printf("%d\n", sum);
	return 0;
}