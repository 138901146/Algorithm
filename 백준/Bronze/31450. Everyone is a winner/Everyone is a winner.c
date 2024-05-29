#include<stdio.h>

int main(void)
{
	int M, K;

	scanf("%d%d", &M, &K);

	printf("%s", (M<K||M%K)?"No":"Yes");
	return 0;
}