#include<stdio.h>

char S[11]={0};
int length=0, count=0, arr[10];

void check_lucky(void)
{
	for(int i=1;i<length;++i)
		if(S[arr[i]]==S[arr[i-1]])
			return;

	++count;
}

void combination(int current,int done)
{
	if(done==length)
	{
		check_lucky();
		return;
	}

	for(int i=0;i<length;++i)
		if(!(current&(1<<i)))
		{
			arr[done]=i;
			combination(1<<i|current,done+1);
		}
}

int factorial(int x)
{
	return x<2?1:x*factorial(x-1);
}

int main(void)
{
	int occur[26]={0}, factorialable=1;

	scanf("%s", S);

	while(S[length])
		++occur[S[length++]-'a'];

	for(int i=0;i<26;++i)
		if(1<occur[i])
		{
			factorialable=0;
			break;
		}

	if(factorialable)
	{
		printf("%d", factorial(length));
		return 0;
	}

	combination(0,0);
	for(int i=0;i<26;++i)
		count/=factorial(occur[i]);

	printf("%d", count);
	return 0;
}