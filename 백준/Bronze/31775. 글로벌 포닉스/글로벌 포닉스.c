#include<stdio.h>

int main(void)
{
	int flag=0;
	char S[3][21]={0};

	for(int i=0;i<3;++i)
	{
		scanf("%s", S[i]);
		if(S[i][0]=='l')
			flag|=1;
		else if(S[i][0]=='k')
			flag|=2;
		else if(S[i][0]=='p')
			flag|=4;
	}

	printf("%s", flag==7?"GLOBAL":"PONIX");
	return 0;
}