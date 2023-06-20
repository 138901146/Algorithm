#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N;
	long long whisper[4]={0, };
	char *S=NULL;

	scanf("%d", &N);
	S=(char *)malloc((N+1)*sizeof(char));

	scanf("%s", S);

	for(int n=0;n<N;n++)
		if(S[n]=='W')
			whisper[0]=(whisper[0]+1)%1000000007;
		else if(S[n]=='H')
			whisper[1]=(whisper[0]+whisper[1])%1000000007;
		else if(S[n]=='E')
		{
			whisper[3]=(whisper[2]+2*whisper[3])%1000000007;
			whisper[2]=(whisper[1]+whisper[2])%1000000007;
		}

	printf("%lld\n", whisper[3]);
	free(S);
	return 0;
}