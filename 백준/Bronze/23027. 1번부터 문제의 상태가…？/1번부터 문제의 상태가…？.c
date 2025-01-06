#include<stdio.h>
#include<string.h>

int main(void)
{
	char S[1001]={0};
	int length, a=0, b=0, c=0;

	scanf("%s", S);
	length=strlen(S);

	for(int i=0;i<length;++i)
		switch(S[i])
		{
			case 'A':
				a=1;
				break;
			case 'B':
				b=1;
				break;
			case 'C':
				c=1;
				break;
			default:
				break;
		}

	if(a)
		for(int i=0;i<length;++i)
			switch(S[i])
			{
				case 'B':
				case 'C':
				case 'D':
				case 'F':
					S[i]='A';
					break;
				default:
					break;
			}
	else if(b)
		for(int i=0;i<length;++i)
			switch(S[i])
			{
				case 'C':
				case 'D':
				case 'F':
					S[i]='B';
					break;
				default:
					break;
			}
	else if(c)
		for(int i=0;i<length;++i)
			switch(S[i])
			{
				case 'D':
				case 'F':
					S[i]='C';
					break;
				default:
					break;
			}
	else
		for(int i=0;i<length;++i)
			S[i]='A';

	printf("%s", S);
	return 0;
}