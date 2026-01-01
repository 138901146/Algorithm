#include<stdio.h>
#include<string.h>

int main(void)
{
	int length[2], shorter;
	char str[2][1001]={0}, replaced[1001]={0};

	for(int i=0;i<2;++i)
	{
		scanf("%s", str[i]);
		length[i]=strlen(str[i]);
	}

	shorter=length[0]<length[1]?length[0]:length[1];
	for(int i=0;i<shorter;++i)
		replaced[i]=str[i&1][i];

	printf("%s", replaced);
	return 0;
}