#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	int length, zero=0, one=0;
	char S[501]={0};
	bool deleted[500]={false};

	scanf("%s", S);
	length=strlen(S);

	for(int i=0;i<length;++i)
		S[i]=='0'?++zero:++one;
	zero>>=1;
	one>>=1;
	for(int i=0;i<length;++i)
		if(S[i]=='1'&&one)
		{
			deleted[i]=true;
			--one;
		}
	for(int i=length-1;0<=i;--i)
		if(S[i]=='0'&&zero)
		{
			deleted[i]=true;
			--zero;
		}

	for(int i=0;i<length;++i)
		if(!deleted[i])
			printf("%c", S[i]);
	return 0;
}