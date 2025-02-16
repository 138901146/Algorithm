#include<stdio.h>

int main(void)
{
	int score, total=0;

	for(int i=0;i<9;++i)
	{
		scanf("%d", &score);

		if(((i>>1)+1)*100<score)
		{
			printf("hacker");
			return 0;
		}

		total+=score;
	}

	printf("%s", total<100?"none":"draw");
	return 0;
}