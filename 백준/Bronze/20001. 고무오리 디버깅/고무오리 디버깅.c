#include<stdio.h>
#include<string.h>

int main(void)
{
	int problem=0;

	while(1)
	{
		char str[30]={'\0', };

		fgets(str,sizeof(str),stdin);

		if(strncmp(str,"문제\n",7)==0)
			problem++;
		else if(strncmp(str,"고무오리\n",13)==0)
			problem+=problem>0?-1:2;
		else if(strncmp(str,"고무오리 디버깅 끝\n",27)==0)
			break;
	}

	printf("%s\n", problem==0?"고무오리야 사랑해":"힝구");
	return 0;
}