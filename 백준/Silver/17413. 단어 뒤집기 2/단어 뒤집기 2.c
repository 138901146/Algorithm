#include<stdio.h>
#include<string.h>

int main(void)
{
	int last=0;
	char S[100001]={'\0', };

    fgets(S,sizeof(S),stdin);

	for(int i=0;i<strlen(S);i++)
		if(S[i]=='<')
		{
			for(int j=i-1;j>=last;j--)
				printf("%c", S[j]);
			while(S[i]!='>')
				printf("%c", S[i++]);
			printf("%c", S[i]);
			last=i+1;
		}
		else if(S[i]==' ' || S[i]=='\n')
		{
			for(int j=i-1;j>=last;j--)
				printf("%c", S[j]);
			printf(" ");
			last=i+1;
		}
		else if(i==strlen(S)-1)
			for(int j=i;j>=last;j--)
				printf("%c", S[j]);

	return 0;
}