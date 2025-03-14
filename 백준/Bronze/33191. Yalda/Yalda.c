#include<stdio.h>

int main(void)
{
	int b, w, p, n;

	scanf("%d", &b);
	scanf("%d", &w);
	scanf("%d", &p);
	scanf("%d", &n);

	if(w<=b)
		printf("Watermelon");
	else if(p<=b)
		printf("Pomegranates");
	else if(n<=b)
		printf("Nuts");
	else
		printf("Nothing");
	return 0;
}