#include<stdio.h>
#include<string.h>

int main(void)
{
	char S[1001]={0};
	int length;

	scanf("%s", S);
	length=strlen(S);

	if(length<5)
		printf("not cute");
	else if(S[length-5]=='d'&&S[length-4]=='r'&&S[length-3]=='i'&&S[length-2]=='i'&&S[length-1]=='p')
		printf("cute");
	else
		printf("not cute");
	return 0;
}