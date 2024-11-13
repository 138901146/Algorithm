#include<stdio.h>

int main(void)
{
	int read=-1, yonsei_count=0, korea_count=0;
	char S[500001]={0}, yonsei[6]={'Y','O','N','S','E','I'}, korea[5]={'K','O','R','E','A'};

	scanf("%s", S);

	while(S[++read])
	{
		if(S[read]==yonsei[yonsei_count] && ++yonsei_count==6)
		{
			printf("YONSEI");
			return 0;
		}
		if(S[read]==korea[korea_count] && ++korea_count==5)
		{
			printf("KOREA");
			return 0;
		}
	}

	return 0;
}