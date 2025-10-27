#include<stdio.h>
#include<string.h>

int main(void)
{
	int length;
	char S[5001]={0};

	scanf("%s", S);
	length=strlen(S);

	for(int i=0;i<length;++i)
		switch(S[i])
		{
			case 'p':
				if(length<=i+1||S[i+1]!='i')
				{
					printf("NO");
					return 0;
				}
				++i;
				break;
			case 'k':
				if(length<=i+1||S[i+1]!='a')
				{
					printf("NO");
					return 0;
				}
				++i;
				break;
			case 'c':
				if(length<=i+2||S[i+1]!='h'||S[i+2]!='u')
				{
					printf("NO");
					return 0;
				}
				i+=2;
				break;
			default:
				printf("NO");
				return 0;
		}

	printf("YES");
	return 0;
}