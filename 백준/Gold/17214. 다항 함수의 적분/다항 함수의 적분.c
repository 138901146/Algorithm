#include<stdio.h>
#include<string.h>

int main(void)
{
	char calculation[20]={'\0', };
	int variable=0, constant=0, index=0, minus[2]={1,1};

	fgets(calculation,sizeof(calculation),stdin);

	if(strlen(calculation)>1)
	{
		if(calculation[index]=='-')
		{
			minus[0]=-1;
			index++;
		}
		while(index<strlen(calculation) && calculation[index]!='x')
		{
			variable*=10;
			variable+=calculation[index++]-'0';
		}
		if(index<strlen(calculation) && calculation[index]=='x')
			index++;
		else
		{
			minus[1]=minus[0];
			minus[0]=1;
			variable-=calculation[index-1]-'0';
			variable/=10;
			constant=variable;
			variable=0;
		}
		if(index<strlen(calculation))
		{
			if(calculation[index]=='-')
				minus[1]=-1;
			index++;
		}
		while(index<strlen(calculation) && calculation[index]>='0' && calculation[index]<='9')
		{
			constant*=10;
			constant+=calculation[index++]-'0';
		}

		variable*=minus[0];
		switch(variable)
		{
			default:
				if(variable==-2)
					printf("-");
				else
					printf("%d", variable/2);
			case 2:
				printf("xx");
				if(minus[1]==1)
					printf("+");
			case 0:
				if(minus[1]==-1)
					printf("-");
				break;
		}
		switch(constant)
		{
			default:
				printf("%d", constant);
			case 1:
				printf("x+");
			case 0:
				break;
		}
	}
	printf("W\n");

	return 0;
}