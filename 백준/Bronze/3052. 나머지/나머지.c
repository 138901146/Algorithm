#include<stdio.h>

int main(void)
{
	int mod[42]={0, }, number;

	for(int i=0;i<10;i++)
	{
		scanf("%d", &number);
		mod[number%42]++;
	}

	number=0;
	for(int i=0;i<42;i++)
		number+=mod[i]>0;

	printf("%d\n", number);

	return 0;
}