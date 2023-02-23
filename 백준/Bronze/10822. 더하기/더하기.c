#include<stdio.h>
#include<string.h>

int main(void)
{
	char S[101]={'\0', };
	int sum=0, temp=0;

	scanf("%s", S);

	for(int i=0;i<strlen(S);i++)
		if(S[i]==',')
		{
			sum+=temp;
			temp=0;
		}
		else
		{
			temp*=10;
			temp+=S[i]-'0';
		}
	sum+=temp;

	printf("%d\n", sum);

	return 0;
}