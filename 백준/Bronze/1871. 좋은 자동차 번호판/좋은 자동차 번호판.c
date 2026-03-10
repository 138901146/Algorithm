#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		int digit, converted;
		char alphabet[3]={0};

		getchar();
		for(int i=0;i<3;++i)
			scanf("%c", &alphabet[i]);
		scanf("%d", &digit);

		digit=-digit;
		converted=676*(alphabet[0]-'A')+26*(alphabet[1]-'A')+alphabet[2]-'A';

		printf("%s\n", abs(converted-digit)<101?"nice":"not nice");
	}

	return 0;
}