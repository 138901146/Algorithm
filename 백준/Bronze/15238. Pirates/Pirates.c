#include<stdio.h>

int main(void)
{
	int size, count[26]={0}, best=0;
	char str[1001]={0};

	scanf("%d", &size);
	scanf("%s", str);

	for(int i=0;i<size;++i)
		++count[str[i]-'a'];

	for(int i=1;i<26;++i)
		best=count[i]<count[best]?best:i;

	printf("%c %d", 'a'+best, count[best]);
	return 0;
}