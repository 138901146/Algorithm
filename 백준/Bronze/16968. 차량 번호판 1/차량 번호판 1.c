#include<stdio.h>

int main(void)
{
	int count;
	char str[5]={0};

	scanf("%s", str);

	count=str[0]=='c'?26:10;		

	for(int i=1;str[i];++i)
		if(str[i]=='c')
			count*=str[i]==str[i-1]?25:26;
		else
			count*=str[i]==str[i-1]?9:10;

	printf("%d", count);
	return 0;
}