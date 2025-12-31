#include<stdio.h>

int main(void)
{
	char S[4]={0};

	scanf("%s", S);

	if(S[0]=='(')
		printf("%d", S[1]=='1'?0:1);
	else if(S[0]=='1')
		printf("1");
	else
		printf("%d", S[1]=='1'?2:1);

	return 0;
}