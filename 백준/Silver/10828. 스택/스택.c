#include<stdio.h>

int main(void)
{
	int N, stack[10000], top=0;

	scanf("%d", &N);
	getchar();

	while(N--)
	{
		char query[15]={'\0'};
		fgets(query,sizeof(query),stdin);

		switch(query[0])
		{
			case 's':
				printf("%d\n", top);
				break;
			case 'e':
				printf("%d\n", !top);
				break;
			case 't':
				printf("%d\n", top?stack[top-1]:-1);
				break;
			default:
				if(query[1]=='u')
				{
					int num;
					sscanf(query+4, "%d", &num);
					stack[top++]=num;
				}
				else
					printf("%d\n", top?stack[--top]:-1);
		}
	}

	return 0;
}