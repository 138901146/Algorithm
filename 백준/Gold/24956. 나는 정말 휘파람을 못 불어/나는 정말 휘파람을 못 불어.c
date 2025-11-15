#include<stdio.h>
#include<malloc.h>

#define MOD 1000000007

int main(void)
{
	int N;
	long long whisper[4]={0};
	char *S=NULL;

	scanf("%d", &N);
	S=(char *)malloc((N+1)*sizeof(char));

	scanf("%s", S);

	for(int n=0;n<N;n++)
		if(S[n]=='W')
			whisper[0]=(whisper[0]+1)%MOD;
		else if(S[n]=='H')
			whisper[1]=(whisper[0]+whisper[1])%MOD;
		else if(S[n]=='E')
		{
			whisper[3]=(whisper[2]+2*whisper[3])%MOD;
			whisper[2]=(whisper[1]+whisper[2])%MOD;
		}

	printf("%lld", whisper[3]);
	free(S);
	return 0;
}