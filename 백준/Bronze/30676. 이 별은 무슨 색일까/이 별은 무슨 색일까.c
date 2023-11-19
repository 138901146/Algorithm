#include<stdio.h>

int main(void)
{
	int lambda;

	scanf("%d", &lambda);

	if(lambda<425)
		printf("Violet");
	else if(lambda<450)
		printf("Indigo");
	else if(lambda<495)
		printf("Blue");
	else if(lambda<570)
		printf("Green");
	else if(lambda<590)
		printf("Yellow");
	else if(lambda<620)
		printf("Orange");
	else
		printf("Red");

	return 0;
}