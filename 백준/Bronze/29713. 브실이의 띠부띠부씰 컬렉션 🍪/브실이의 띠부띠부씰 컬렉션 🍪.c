#include<stdio.h>

int main(void)
{
	int N, count[26]={0}, check1[8]={1, 8, 11, 13, 14, 18, 21, 25}, check2[2]={4, 17}, max=99;
	char str[1001]={0};

	scanf("%d", &N);
	scanf("%s", str);

	while(N--)
		++count[str[N]-'A'];

	for(int i=0;i<8;++i)
		max=count[check1[i]]<max?count[check1[i]]:max;
	for(int i=0;i<2;++i)
		max=count[check2[i]]/2<max?count[check2[i]]/2:max;

	printf("%d", max);
	return 0;
}