#include<stdio.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		char str[1000]={'\0', };

		scanf("%s", str);

		printf("%c%c\n", str[0], str[strlen(str)-1]);
	}

	return 0;
}