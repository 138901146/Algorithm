#include<stdio.h>

int main(void)
{
	int N, file[50], cluster;
	long long total=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		scanf("%d", &file[i]);
	scanf("%d", &cluster);

	for(int i=0;i<N;++i)
		if(!file[i])
			continue;
		else
			total+=(long long)cluster*(file[i]/cluster+(file[i]%cluster!=0));

	printf("%lld", total);
	return 0;
}