#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

bool isPrime(int N)
{
	if(N==1 || N==2)
		return true;
	else if(N%2==0 || N<1)
		return false;
	else
		for(int i=3;i*i<=N;i++)
			if(N%i==0)
				return false;

	return true;
}

int main(void)
{
	int sum=0;
	char word[21]={'\0', };

	scanf("%s", word);

	for(int i=0;i<strlen(word);i++)
		sum+=islower(word[i])?word[i]-'a'+1:word[i]-'A'+27;

	printf("%s\n", isPrime(sum)?"It is a prime word.":"It is not a prime word.");
	return 0;
}