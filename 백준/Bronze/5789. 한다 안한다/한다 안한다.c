#include<stdio.h>
#include<string.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		char str[1001]={0};

		scanf("%s", str);
		printf("Do-it%s\n", str[strlen(str)>>1]==str[(strlen(str)>>1)-1]?"":"-Not");
	}

	return 0;
}