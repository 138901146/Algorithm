#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[31]={'\0', };
	int correct[30], current=0, calculate[30]={0, };

	scanf("%s", str);
	for(int i=0;i<strlen(str);i++)
		switch(str[i])
		{
			case '(':
				correct[current++]=0;
				break;
			case '[':
				correct[current++]=1;
				break;
			case ')':
				if(current<=0)
				{
					printf("0\n");
					return 0;
				}
				if(correct[--current]!=0)
				{
					printf("0\n");
					return 0;
				}
				break;
			case ']':
				if(current<=0)
				{
					printf("0\n");
					return 0;
				}
				if(correct[--current]!=1)
				{
					printf("0\n");
					return 0;
				}
				break;
			default:
				printf("0\n");
				return 0;
		}
	if(current!=0)
	{
		printf("0\n");
		return 0;
	}

	for(int i=0;i<strlen(str);i++)
		switch(str[i])
		{
			case '(':
			case '[':
				current++;
				break;
			case ')':
				calculate[current-1]+=2*(calculate[current]==0?1:calculate[current]);
				calculate[current]=0;
				current--;
				break;
			case ']':
				calculate[current-1]+=3*(calculate[current]==0?1:calculate[current]);
				calculate[current]=0;
				current--;
				break;
		}

	printf("%d\n", calculate[0]);
	return 0;
}