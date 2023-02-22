#include<stdio.h>

int main(void)
{
	int number[5];

	for(int n=0;n<5;n++)
		scanf("%d", &number[n]);

	for(int mul=4;;mul++)
	{
		int count=0;

		for(int n=0;n<5;n++)
			count+=mul%number[n]==0;

		if(count>2)
		{
			printf("%d\n", mul);
			break;
		}
	}

	return 0;
}