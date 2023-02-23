#include<stdio.h>

int main(void)
{
	int Apples=0, Bananas=0, score;

	for(int i=3;i>0;i--)
	{
		scanf("%d", &score);
		Apples+=i*score;
	}
	for(int i=3;i>0;i--)
	{
		scanf("%d", &score);
		Bananas+=i*score;
	}

	printf("%c\n", Apples>Bananas?'A':Apples<Bananas?'B':'T');
	return 0;
}