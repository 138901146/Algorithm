#include<stdio.h>

int main(void)
{
	int score;

	scanf("%d", &score);
	printf("%c", score>=90?'A':score>=80?'B':score>=70?'C':score>=60?'D':'F');

	return 0;
}