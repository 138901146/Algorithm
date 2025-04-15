#include<stdio.h>

int main(void)
{
	int count[26]={0};
	char str[26]={0};

	scanf("%s", str);

	for(int i=0;i<25;++i)
		++count[str[i]-'A'];

	for(int i=0;i<26;++i)
		if(!count[i])
			printf("%c", 'A'+i);

	return 0;
}