#include<stdio.h>

int main(void)
{
	int K, N, power[100], speed[100], intelligence[100], stat=1000000000;

	scanf("%d%d", &N, &K);

	for(int n=0;n<N;++n)
		scanf("%d%d%d", &power[n], &speed[n], &intelligence[n]);

	for(int p=0;p<N;++p)
		for(int s=0;s<N;++s)
			for(int i=0;i<N;++i)
			{
				int count=0;

				for(int soilder=0;soilder<N;++soilder)
					count+=power[p]>=power[soilder]&&speed[s]>=speed[soilder]&&intelligence[i]>=intelligence[soilder];

				if(K<=count&&power[p]+speed[s]+intelligence[i]<stat)
					stat=power[p]+speed[s]+intelligence[i];
			}

	printf("%d", stat);
	return 0;
}