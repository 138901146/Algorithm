#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	char str[101]={'\0', };

	gets(str);
	while(strcmp(str,".")!=0)
	{
		int check[101]={0, }, current=0;
		bool able=true;

		for(int i=0;str[i]!='.';i++)
		{
			switch(str[i])
			{
				case '(':
					check[current++]=1;
					break;
				case '[':
					check[current++]=2;
					break;
				case ')':
					if(current==0)
						able=false;
					else if(check[--current]!=1)
						able=false;
					break;
				case ']':
					if(current==0)
						able=false;
					else if(check[--current]!=2)
						able=false;
					break;
			}
			if(!able)
				break;
		}

		printf("%s\n", able&&current==0?"yes":"no");

		for(int i=0;i<101;i++)
			str[i]='\0';
		gets(str);
	}

	return 0;
}