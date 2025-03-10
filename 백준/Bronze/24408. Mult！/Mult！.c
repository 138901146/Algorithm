#include<stdio.h>

int main(void)
{
	int n, first, number, done=1;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &number);

		if(done)
		{
			done=0;
			first=number;
		}
		else if(first<=number && number%first==0)
		{
			printf("%d\n", number);
			done=1;
		}
	}

	return 0;
}