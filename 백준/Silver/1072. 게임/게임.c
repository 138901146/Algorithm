#include<stdio.h>

int main(void)
{
	long int X, Y, Z, count=0, left=0, right=1000000000;

	scanf("%ld %ld", &X, &Y);

	Z=(Y*100)/X;
	if(Z>=99)
		count=-1;
	else
	{
		while(left<right-1)
		{
			count=(left+right)/2;

			if(((Y+count)*100)/(X+count)==Z)
				left=count;
			else
				right=count;
		}

		if(((Y+count)*100)/(X+count)==Z)
			count++;
	}

	printf("%ld\n", count);
	return 0;
}