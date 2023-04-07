#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int T, N, K, *D=NULL, W, **pri_order=NULL, **def_order=NULL, *pri_count=NULL, *def_count=NULL, *primitive=NULL, *definitive=NULL, *queue=NULL, *construct=NULL, front, rear, previous_rear;

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		scanf("%d%d", &N, &K);
		pri_order=(int **)malloc((N+1)*sizeof(int *));
		def_order=(int **)malloc((N+1)*sizeof(int *));
		pri_count=(int *)calloc(N+1,sizeof(int));
		def_count=(int *)calloc(N+1,sizeof(int));
		primitive=(int *)malloc(K*sizeof(int));
		definitive=(int *)malloc(K*sizeof(int));
		construct=(int *)calloc(N+1,sizeof(int));
		queue=(int *)malloc(N*sizeof(int));
		D=(int *)malloc((N+1)*sizeof(int));
		front=rear=0;

		for(int n=1;n<=N;n++)
			scanf("%d", &D[n]);
		for(int k=0;k<K;k++)
		{
			scanf("%d%d", &primitive[k], &definitive[k]);
			pri_count[primitive[k]]++;
			def_count[definitive[k]]++;
		}
		scanf("%d", &W);

		for(int n=1;n<=N;n++)
		{
			pri_order[n]=(int *)malloc((pri_count[n]+1)*sizeof(int));
			def_order[n]=(int *)malloc((def_count[n]+1)*sizeof(int));
			pri_order[n][0]=def_order[n][0]=0;
		}

		for(int k=0;k<K;k++)
		{
			pri_order[primitive[k]][++pri_order[primitive[k]][0]]=definitive[k];
			def_order[definitive[k]][++def_order[definitive[k]][0]]=primitive[k];
		}

		for(int n=1;n<=N;n++)
			if(def_count[n]==0)
				queue[rear++]=n;

		while(front<rear)
		{
			previous_rear=rear;

			while(front<previous_rear)
			{
				int max=0;
				for(int i=1;i<=def_order[queue[front]][0];i++)
					if(construct[def_order[queue[front]][i]]>max)
						max=construct[def_order[queue[front]][i]];
				construct[queue[front]]=max+D[queue[front]];

				for(int i=1;i<=pri_count[queue[front]];i++)
				{
					def_count[pri_order[queue[front]][i]]--;
					if(def_count[pri_order[queue[front]][i]]==0)
						queue[rear++]=pri_order[queue[front]][i];
				}
				front++;
				if(queue[front-1]==W)
					break;
			}

			if(queue[front-1]==W)
				break;
		}

		printf("%d\n", construct[W]);
		for(int n=1;n<=N;n++)
		{
			free(pri_order[n]);
			free(def_order[n]);
		}
		free(pri_order);
		free(def_order);
		free(pri_count);
		free(def_count);
		free(primitive);
		free(definitive);
		free(construct);
		free(queue);
		free(D);
	}

	return 0;
}