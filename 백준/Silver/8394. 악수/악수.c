#include<stdio.h>

int main(void)
{
	int n, handshake[3][2]={0}, previous=0, current=1, next=2;

	scanf("%d", &n);

	handshake[0][0]=handshake[1][0]=1;
	for(int i=2;i<=n;++i)
	{
		handshake[next][0]=(handshake[current][0]+handshake[current][1])%10;
		handshake[next][1]=(handshake[previous][0]+handshake[previous][1])%10;
		previous=(previous+1)%3;
		current=(current+1)%3;
		next=(next+1)%3;
	}

	printf("%d", (handshake[current][0]+handshake[current][1])%10);
	return 0;
}