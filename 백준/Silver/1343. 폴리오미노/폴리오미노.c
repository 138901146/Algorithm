#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	int start=0;
	char board[501]={'\0', };
	bool error=false;

	scanf("%s", board);

	while(start<strlen(board))
	{
		while(board[start]=='.')
			start++;
		int end=start;
		while(board[end]!='.' && end<strlen(board))
			end++;

		if((end-start)%2!=0)
		{
			error=true;
			printf("-1\n");
			break;
		}

		while(end-start>=4)
			for(int i=0;i<4;i++)
				board[start++]='A';
		while(end-start>=2)
			for(int i=0;i<2;i++)
				board[start++]='B';
	}

	if(!error)
		printf("%s\n", board);
	return 0;
}