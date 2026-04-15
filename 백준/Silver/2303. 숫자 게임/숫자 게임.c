#include<stdio.h>

int main(void)
{
	int N, arr[5], max=-1, id;

	scanf("%d", &N);

	for(int i=1;i<=N;++i)
	{
		for(int j=0;j<5;++j)
			scanf("%d", &arr[j]);

		for(int j=0;j<5;++j)
			for(int k=j+1;k<5;++k)
				for(int l=k+1;l<5;++l)
					if(max<=(arr[j]+arr[k]+arr[l])%10)
					{
						id=i;
						max=(arr[j]+arr[k]+arr[l])%10;
					}
	}

	printf("%d", id);
	return 0;
}