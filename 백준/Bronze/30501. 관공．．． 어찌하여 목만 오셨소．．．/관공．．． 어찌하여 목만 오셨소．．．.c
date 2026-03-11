#include<stdio.h>
#include<string.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N--)
	{
		char name[101]={0};

		scanf("%s", name);

		for(int i=0;i<strlen(name);++i)
			if(name[i]=='S')
			{
				printf("%s", name);
				return 0;
			}
	}

	return 0;
}