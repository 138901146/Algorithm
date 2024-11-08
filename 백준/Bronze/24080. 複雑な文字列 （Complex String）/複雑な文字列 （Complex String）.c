#include<stdio.h>

int main(void)
{
	int N, count[26]={0}, sum=0;
	char S[101]={0};

	scanf("%d", &N);
	scanf("%s", S);

	for(int n=0;n<N;++n)
		if('a'<=S[n]&&S[n]<='z')
			count[S[n]-'a']=1;
		else
			count[S[n]-'A']=1;

	for(int i=0;i<26;++i)
		sum+=count[i];

	printf("%s", sum<3?"No":"Yes");
	return 0;
}