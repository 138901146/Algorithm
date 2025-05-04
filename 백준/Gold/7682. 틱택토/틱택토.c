#include<stdio.h>

int main(void)
{
	int winning_case[8][3]={{0,1,2},{0,3,6},{0,4,8},{1,4,7},{2,4,6},{2,5,8},{3,4,5},{6,7,8}};
	char board[10]={0};

	scanf("%s", board);

	while(board[0]!='e')
	{
		int o_count=0, x_count=0, bingo[8], bingo_count=0;

		for(int i=0;i<9;++i)
		{
			o_count+=board[i]=='O';
			x_count+=board[i]=='X';
		}

		for(int i=0;i<8;++i)
			if(board[winning_case[i][0]]!='.' && board[winning_case[i][0]]==board[winning_case[i][1]] && board[winning_case[i][0]]==board[winning_case[i][2]])
				bingo[bingo_count++]=i;

		if(x_count<o_count || o_count+1<x_count)
			printf("invalid\n");
		else if(bingo_count==1)
		{
			int valid;

			if(board[winning_case[bingo[0]][0]]=='X')
				valid=x_count!=o_count;
			else
				valid=x_count==o_count;

			printf("%s\n", valid?"valid":"invalid");
		}
		else if(1<bingo_count)
		{
			int duplicate=0;

			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					if(winning_case[bingo[0]][i]==winning_case[bingo[1]][j])
						duplicate=1;
			printf("%s\n", duplicate?"valid":"invalid");
		}
		else if(o_count+x_count==9)
			printf("valid\n");
		else
			printf("invalid\n");

		scanf("%s", board);
	}

	return 0;
}