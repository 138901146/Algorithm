#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, length[200]={0}, max=1;
		float w[200], c[200];

		scanf("%d", &N);

		for(int n=0;n<N;++n)
			scanf("%f%f", &w[n], &c[n]);

		for(int i=0;i<N;++i)
		{
			for(int j=i-1;0<=j;--j)
				if(w[j]<w[i]&&c[i]<c[j])
					length[i]=length[i]<length[j]?length[j]:length[i];
			++length[i];
			max=length[i]<max?max:length[i];
		}

		printf("%d\n", max);
	}

	return 0;
}