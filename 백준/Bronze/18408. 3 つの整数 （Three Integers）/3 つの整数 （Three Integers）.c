#include<stdio.h>

int main(void)
{
	int one=0, two=0, num;

	for(int i=0;i<3;++i)
	{
		scanf("%d", &num);

		if(num==1)
			++one;
		else
			++two;
	}

	printf("%d", 1+(one<two));
	return 0;
}