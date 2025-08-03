#include<stdio.h>

int main(void)
{
	int Y;

	scanf("%d", &Y);

	for(int D=Y+1;;++D)
	{
		int count[10]={0}, d=D, available=1;

		while(d)
		{
			if(count[d%10])
			{
				available=0;
				break;
			}
			++count[d%10];
			d/=10;
		}

		if(available)
		{
			printf("%d", D);
			return 0;
		}
	}

	return 0;
}