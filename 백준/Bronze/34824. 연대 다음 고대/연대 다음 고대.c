#include<stdio.h>
#include<string.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		char univ[51]={0};

		scanf("%s", univ);

		if(!strcmp(univ,"yonsei"))
		{
			printf("Yonsei Won!");
			return 0;
		}
		else if(!strcmp(univ,"korea"))
		{
			printf("Yonsei Lost...");
			return 0;
		}
	}

	return 0;
}