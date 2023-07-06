#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *color=NULL, max;
	long long count, left=0, right=2000000000, mid, ans=2000000000;

	scanf("%d%d", &N, &M);
	color=(int *)malloc(M*sizeof(int));

	for(int m=0;m<M;m++)
		scanf("%d", &color[m]);

	while(left<=right && right>1)
	{
		max=count=0;
		mid=(left+right)>>1;

		for(int m=0;m<M;m++)
		{
			if(color[m]>=mid)
			{
				count+=color[m]/mid;
				max=mid>max?mid:max;
			}
			if(color[m]%mid!=0)
			{
				count++;
				max=color[m]%mid>max?color[m]%mid:max;
			}
		}

		if(count<=N)
		{
			right=mid-1;
			ans=max<ans?max:ans;
		}
		else
			left=mid+1;
	}

	printf("%lld\n", ans);
	free(color);
	return 0;
}