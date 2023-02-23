#include<stdio.h>
#include<string.h>

int croatiacheck(char a,char b,char c)
{
	switch (a)
	{
		case 'c':
			return b=='='||b=='-';
		case 'd':
			return b=='-'?1:b=='z'?c=='='?2:0:0;
		case 'l':
			return b=='j';
		case 'n':
			return b=='j';
		case 's':
			return b=='=';
		case 'z':
			return b=='=';
		default:
			return 0;
	}
}

int main(void)
{
	char word[100]={'\0', };
	int count=0;

	scanf("%s", word);

	for(int i=0;i<strlen(word)-1;i++)
	{
		int temp=croatiacheck(word[i],word[i+1],word[i+2]);

		word[i+1]=temp==2?'a':word[i+1];
		count+=temp;
	}
	printf("%d", (int)strlen(word)-count);

	return 0;
}