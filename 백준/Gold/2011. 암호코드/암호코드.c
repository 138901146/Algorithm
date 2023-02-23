#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char password[5001]={'\0', };
	int *code=NULL;

	scanf("%s", password);
	code=(int *)calloc(strlen(password),sizeof(int));

	if(password[0]=='0')
		code[0]=code[1]=0;
	else if(password[1]=='0')
		if(password[0]<'3')
			code[0]=code[1]=1;
		else
			code[0]=code[1]=0;
	else
	{
		code[0]=code[1]=1;
		if(password[0]<'2' || password[0]=='2'&&password[1]<'7')
			code[1]=2;
	}

	for(int i=2;i<strlen(password);i++)
	{
		code[i]=code[i-1];
		if(password[i]=='0')
		{
			if(password[i-1]>'0' && password[i-1]<'3')
				code[i]=code[i-2];
			else
				code[i]=code[i-1]=0;
		}
		else if(password[i-1]=='0');
		else if(password[i-1]<'2' || password[i-1]=='2'&&password[i]<'7')
			code[i]+=code[i-2];

		code[i]%=1000000;
	}

	printf("%d\n", (code[strlen(password)-1]));
	free(code);
	return 0;
}