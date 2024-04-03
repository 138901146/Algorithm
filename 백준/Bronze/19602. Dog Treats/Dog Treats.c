#include<stdio.h>

int main(void)
{
	int S, M, L;

	scanf("%d", &S);
	scanf("%d", &M);
	scanf("%d", &L);

	printf("%s", S+(M<<1)+3*L<10?"sad":"happy");
	return 0;
}