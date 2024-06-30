#include<stdio.h>

int main(void)
{
	int T, tea, answer=0;

	scanf("%d", &T);

	for(int i=0;i<5;++i)
	{
		scanf("%d", &tea);
		answer+=T==tea;
	}

	printf("%d", answer);
	return 0;
}