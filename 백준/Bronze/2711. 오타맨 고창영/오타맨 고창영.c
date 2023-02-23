#include<stdio.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int loc;
		char str[80]={'\0', };

		scanf("%d %s", &loc, str);

		for(int i=0;i<strlen(str);i++)
			if(i+1!=loc)
				printf("%c", str[i]);
		printf("\n");
	}

	return 0;
}