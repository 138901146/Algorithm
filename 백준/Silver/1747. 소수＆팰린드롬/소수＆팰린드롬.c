#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isPrime(int N)
{
	if(N<2)
		return false;
	else if(N==2)
		return true;
	else if(N%2==0)
		return false;
	else
		for(int i=3;i*i<=N;i+=2)
			if(N%i==0)
				return false;
	return true;
}

bool isPalindrome(char *str,int length)
{
	for(int i=0;i<length/2;i++)
		if(str[i]!=str[length-1-i])
			return false;
	return true;
}

int main(void)
{
	int N;
	char str[8]={'\0', };

	scanf("%d", &N);
	sprintf(str,"%d",N);

	while(!isPrime(N)||!isPalindrome(str,strlen(str)))
		sprintf(str,"%d",++N);

	printf("%d\n", N);
	return 0;
}