#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool is_vowel(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main(void)
{
	int length, second=0;
	char S[101]={0};

	scanf("%s", S);

	length=strlen(S);

	if(is_vowel(S[length-1])||S[length-1]=='n'||S[length-1]=='s')
		second=1;

	for(int i=length-1;0<=i;--i)
		if(is_vowel(S[i]))
		{
			if(second)
				--second;
			else
			{
				printf("%d", i+1);
				return 0;
			}
		}

	printf("-1");
	return 0;
}