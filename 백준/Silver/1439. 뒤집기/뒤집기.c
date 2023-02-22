#include<stdio.h>
#include<string.h>

int main(void)
{
	char S[1000001]={'\0', };
	int zero=0, one=0;

	scanf("%s", S);

	for(int s=1;s<strlen(S);s++)
		if(S[s]!=S[s-1])
		{
			if(S[s-1]=='0')
				zero++;
			else
				one++;
		}
	if(S[strlen(S)-1]=='0')
		zero++;
	else
		one++;

	printf("%d\n", zero>one?one:zero);
	return 0;
}