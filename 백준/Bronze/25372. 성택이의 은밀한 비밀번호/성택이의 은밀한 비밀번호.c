#include<stdio.h>
#include<string.h>

int main(void)
{
	int N;

	scanf("%d", &N);
	getchar();

	while(N--)
	{
		char password[21]={0};
		scanf("%s", password);
		printf("%s\n", 6<=strlen(password)&&strlen(password)<=9?"yes":"no");
	}

	return 0;
}