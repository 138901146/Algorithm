#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, page, lack[100], lack_count=0, ink=7;
	bool exist[101]={false};

	scanf("%d%d", &N, &M);

	while(M--)
	{
		scanf("%d", &page);
		exist[page]=true;
	}

	for(int i=1;i<=N;++i)
		if(!exist[i])
			lack[lack_count++]=i;

	if(!lack_count)
	{
		printf("0");
		return 0;
	}

	for(int i=1;i<lack_count;++i)
		ink+=lack[i]-lack[i-1]<4?lack[i]-lack[i-1]<<1:7;

	printf("%d", ink);
	return 0;
}