#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<memory.h>

typedef struct
{
	short computer;
	short software;
}
edge;

short **class, *class_size=NULL, *occupied=NULL;
bool *flag=NULL;

bool dfs(short current)
{
	for(short i=0;i<class_size[current];++i)
	{
		short next=class[current][i];

		if(!flag[next])
		{
			flag[next]=true;

			if(!occupied[next] || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	short n, N, duplicate=0;
	int m;
	char major;
	edge *common=NULL;

	scanf("%hd%d", &n, &m);

	class=(short **)malloc((n+1)*sizeof(short *));
	class_size=(short *)calloc(n+1,sizeof(short));
	flag=(bool *)calloc(n+1,sizeof(bool));
	common=(edge *)malloc(m*sizeof(edge));

	for(short i=0;i<n;++i)
	{
		scanf("%hd %c", &N, &major);
		flag[N]=major=='c';
	}

	for(int i=0;i<m;++i)
	{
		scanf("%hd", &common[i].computer);

		if(flag[common[i].computer])
			scanf("%hd", &common[i].software);
		else
		{
			common[i].software=common[i].computer;
			scanf("%hd", &common[i].computer);
		}

		++class_size[common[i].computer];
	}

	for(short i=1;i<=n;++i)
		if(class_size[i])
		{
			class[i]=(short *)malloc(class_size[i]*sizeof(short));
			class_size[i]=0;
		}

	while(m--)
		class[common[m].computer][class_size[common[m].computer]++]=common[m].software;

	free(common);
	occupied=(short *)calloc(n+1,sizeof(short));

	for(short i=1;i<=n;++i)
	{
		memset(flag,0,(n+1)*sizeof(bool));
		duplicate+=dfs(i);
	}

	printf("%hd", n-duplicate);
	for(short i=1;i<=n;++i)
		if(class_size[i])
			free(class[i]);
	free(class);
	free(class_size);
	free(occupied);
	free(flag);
	return 0;
}