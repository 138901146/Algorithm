#include<stdio.h>

int main(void)
{
	short Q, x, y, forum=0;

	scanf("%hd", &Q);

	while(Q--)
	{
		scanf("%hd%hd", &x, &y);

		if(x==1)
			forum+=y;
		else
		{
			if(forum<y)
			{
				printf("Adios");
				return 0;
			}
			forum-=y;
		}
	}

	printf("See you next month");
	return 0;
}