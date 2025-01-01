#include<stdio.h>

char str[100001]={0};

int main(void)
{
	int N, count[26]={0}, most=0;

	scanf("%d", &N);
	getchar();
	fgets(str,sizeof(str),stdin);

	for(int n=0;n<N;++n)
		if('a'<=str[n] && str[n]<='z')
			++count[str[n]-'a'];

	for(int i=0;i<26;++i)
		most=count[i]<most?most:count[i];

	printf("%d", most);
	return 0;
}