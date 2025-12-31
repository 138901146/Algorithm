#include<stdio.h>

int main(void)
{
	int N, count=0;
	char S;

	scanf("%d", &N);

	getchar();
	for(int i=0;i<N;++i)
	{
		S=getchar();
		count+=S=='O';
	}

	printf("%s", (count<<1)<N?"No":"Yes");
	return 0;
}