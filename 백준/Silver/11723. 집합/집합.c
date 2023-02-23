#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

int main(void)
{
	bool S[21]={false, };
	int M;

	scanf("%d", &M);
	getchar();

	for(int m=0;m<M;m++)
	{
		int x;
		char command[10]={'\0', };

		getchar();
		fgets(command,sizeof(command),stdin);

		switch(command[0])
		{
			case 'd':		//add
						x=isdigit(command[4])?10*(command[3]-'0')+command[4]-'0':command[3]-'0';
						S[x]=true;
						break;
			case 'e':		//remove
						x=isdigit(command[7])?10*(command[6]-'0')+command[7]-'0':command[6]-'0';
						S[x]=false;
						break;
			case 'h':		//check
						x=isdigit(command[6])?10*(command[5]-'0')+command[6]-'0':command[5]-'0';
						printf("%d\n", S[x]);
						break;
			case 'o':		//toggle
						x=isdigit(command[7])?10*(command[6]-'0')+command[7]-'0':command[6]-'0';
						S[x]=S[x]==true?false:true;
						break;
			case 'l':		//all
						for(x=1;x<21;x++)
							S[x]=true;
						break;
			case 'm':		//empty
						for(x=1;x<21;x++)
							S[x]=false;
						break;
		}
	}

	return 0;
}