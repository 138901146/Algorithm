#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[51]={0};
	int left=-1, right, length;

	scanf("%s", str);
	length=strlen(str);

	for(int i=0;i<length;++i)
		if(str[i]=='U')
			left=left<0?i:left;
		else if(str[i]=='F')
			right=i;

	for(int i=0;i<left;++i)
		printf("-");
	printf("U");
	for(int i=left+1;i<right;++i)
		printf("C");
	printf("F");
	for(int i=right+1;i<length;++i)
		printf("-");
	return 0;
}