#include<stdio.h>

int main(void)
{
	int t;

	scanf("%d", &t);

	while(t--)
	{
		int n, winner[2]={0};
		char choice[2];

		scanf("%d", &n);

		while(n--)
		{
			getchar();
			scanf("%c %c", &choice[0], &choice[1]);

			if(choice[0]==choice[1])
				continue;
			else if(choice[0]=='R')
				if(choice[1]=='P')
					++winner[1];
				else
					++winner[0];
			else if(choice[0]=='P')
				if(choice[1]=='R')
					++winner[0];
				else
					++winner[1];
			else
				if(choice[1]=='R')
					++winner[1];
				else
					++winner[0];
		}

		printf("%s\n", winner[0]<winner[1]?"Player 2":winner[1]<winner[0]?"Player 1":"TIE");
	}

	return 0;
}