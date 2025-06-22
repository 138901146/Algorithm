#include<stdio.h>

int main(void)
{
	int N, M, chemi[201][2]={0}, convert[26]={3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1}, n=0, m=0, current=0, next=1, simulate;
	char A[101]={0}, B[101]={0};

	scanf("%d%d", &N, &M);
	scanf("%s%s", A, B);

	simulate=N+M;
	for(int i=0;i<simulate;++i)
		if(i&1)
			chemi[i][0]=m<M?convert[B[m++]-'A']:convert[A[n++]-'A'];
		else
			chemi[i][0]=n<N?convert[A[n++]-'A']:convert[B[m++]-'A'];

	while(simulate--)
	{
		for(int i=0;i<simulate;++i)
			chemi[i][next]=(chemi[i][current]+chemi[i+1][current])%10;
		current^=1;
		next^=1;
	}

	if(chemi[0][current])
		printf("%d", chemi[0][current]);
	printf("%d%%", chemi[1][current]);
	return 0;
}