#include<stdio.h>

int isalpha(char c)
{
	return 'a'<=c && c<='z' || 'A'<=c && c<='Z';
}

int main(void)
{
	char str[1000001]={0};
	int count;

	fgets(str,sizeof(str),stdin);

	count=isalpha(str[0]);
	for(int i=1;str[i];++i)
		count+=isalpha(str[i])&&!isalpha(str[i-1]);

	printf("%d", count);
	return 0;
}