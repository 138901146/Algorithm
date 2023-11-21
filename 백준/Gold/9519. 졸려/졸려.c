#include<stdio.h>
#include<string.h>

int main(void)
{
	int X, len, count=1;
	char origin[1001]={'\0'}, str[2][1001]={'\0'};

	scanf("%d", &X);
	scanf("%s", origin);
	len=strlen(origin);
	strcpy(str[0],origin);

	for(int i=0;i<len;++i)
		if((i<<1)<len)
			str[1][i<<1]=str[0][i];
		else
			str[1][(len-i<<1)-1]=str[0][i];

	for(int i=1;strcmp(str[i&1],origin)!=0;++i,++count)
		for(int j=0;j<len;++j)
			if((j<<1)<len)
				str[i&1^1][j<<1]=str[i&1][j];
			else
				str[i&1^1][(len-j<<1)-1]=str[i&1][j];

	X%=count;
	X=count-X;
	strcpy(str[0],origin);

	for(int x=0;x<X;++x)
		for(int i=0;i<len;++i)
			if((i<<1)<len)
				str[x&1^1][i<<1]=str[x&1][i];
			else
				str[x&1^1][(len-i<<1)-1]=str[x&1][i];

	printf("%s", str[X&1]);
	return 0;
}