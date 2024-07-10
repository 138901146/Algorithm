#include<stdio.h>

int main(void)
{
	char jh[5], friend[5];
	int N, count=0;

	scanf("%s", jh);
	scanf("%d", &N);

	while(N--)
	{
		getchar();
		scanf("%s", friend);
		count+=jh[0]==friend[0] && jh[1]==friend[1] && jh[2]==friend[2] && jh[3]==friend[3];
	}

	printf("%d", count);
	return 0;
}