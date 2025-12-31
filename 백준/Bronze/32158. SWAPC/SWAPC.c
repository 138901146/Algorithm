#include<stdio.h>

int main(void)
{
	short length, p[100], c[100], p_count=0, c_count=0, min;
	char S[101]={0};

	scanf("%d", &length);
	scanf("%s", S);

	for(short i=0;i<length;++i)
		if(S[i]=='P')
			p[p_count++]=i;
		else if(S[i]=='C')
			c[c_count++]=i;

	min=p_count<c_count?p_count:c_count;
	for(short i=0;i<min;++i)
	{
		S[p[i]]='C';
		S[c[i]]='P';
	}

	printf("%s", S);
	return 0;
}