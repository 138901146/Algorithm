#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, m, fib[3]={0,1}, previous=0, current=1, next=2;
	char *result=NULL;

	scanf("%d%d", &n, &m);
	result=(char *)calloc(m-n+2,sizeof(char));

	for(int i=1;i<n;++i)
	{
		fib[next]=(fib[previous]+fib[current])%10;
		previous=(previous+1)%3;
		current=(current+1)%3;
		next=(next+1)%3;
	}

	for(int i=n;i<=m;++i)
	{
		result[i-n]=fib[current]+'0';
		fib[next]=(fib[previous]+fib[current])%10;
		previous=(previous+1)%3;
		current=(current+1)%3;
		next=(next+1)%3;
	}

	printf("%s", result);
	return 0;
	free(result);
}