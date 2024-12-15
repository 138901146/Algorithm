#include<stdio.h>

int main(void)
{
	char subject[7][24]={0};
	int score, max=0, best=0;

	for(int i=0;i<7;++i)
	{
		scanf("%s%d", subject[i], &score);
		if(max<score)
		{
			max=score;
			best=i;
		}
	}

	printf("%s", subject[best]);
	return 0;
}