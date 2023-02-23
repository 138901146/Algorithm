#include<stdio.h>

int main(void)
{
	int r, w, l;

	scanf("%d", &r);

	for(int i=1;r!=0;i++)
	{
		scanf("%d %d", &w, &l);

		if(4*r*r>=w*w+l*l)
			printf("Pizza %d fits on the table.\n", i);
		else
			printf("Pizza %d does not fit on the table.\n", i);

		scanf("%d", &r);
	}

	return 0;
}