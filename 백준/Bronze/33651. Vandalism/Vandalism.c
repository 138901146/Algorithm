#include<stdio.h>

int main(void)
{
	int exist[4]={0};
	char s[4]={0}, print[4]={'U','A','P','C'};

	scanf("%s", s);

	for(int i=0;i<4;++i)
		switch(s[i])
		{
			case 'U':
				exist[0]=1;
				break;
			case 'A':
				exist[1]=1;
				break;
			case 'P':
				exist[2]=1;
				break;
			case 'C':
				exist[3]=1;
				break;
		}

	for(int i=0;i<4;++i)
		if(!exist[i])
			printf("%c", print[i]);
	return 0;
}
