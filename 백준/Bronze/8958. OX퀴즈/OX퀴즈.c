#include<stdio.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);
	while(getchar()!='\n');

	for(int i=0;i<T;i++)
	{
		int score=0, con=1;
		char mark[80]={'\0', };

		gets(mark);
		for(int j=0;j<strlen(mark);j++)
			if(mark[j]=='O')
				score+=con++;
			else
				con=1;
		printf("%d\n", score);
	}

	return 0;
}