#include<stdio.h>

int main(void)
{
	int t=0, l=0;
	char str[6]={0};

	for(int i=0;i<9;++i)
	{
		scanf("%s", str);
		str[0]=='T'?++t:++l;
	}

	printf("%s", t<l?"Lion":"Tiger");
	return 0;
}