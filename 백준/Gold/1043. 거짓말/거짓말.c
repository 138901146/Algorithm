#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *party=NULL;

int find_set(int x)
{
	if(x==party[x])
		return x;
	else
		return party[x]=find_set(party[x]);
}

void union_set(int x,int y)
{
	if(find_set(x)!=find_set(y))
		party[find_set(y)]=find_set(x);
}

int main(void)
{
	int N, M, truth_count, person, count=0, *party_root=NULL, **party_people=NULL, *party_size=NULL;
	bool *truth=NULL;

	scanf("%d%d", &N, &M);
	party=(int *)malloc((N+1)*sizeof(int));
	truth=(bool *)calloc(N+1,sizeof(bool));
	party_root=(int *)malloc(M*sizeof(int));
	party_people=(int **)malloc(M*sizeof(int *));
	party_size=(int *)malloc(M*sizeof(int));

	for(int n=1;n<=N;n++)
		party[n]=n;

	scanf("%d", &truth_count);
	for(int i=0;i<truth_count;i++)
	{
		scanf("%d", &person);
		truth[person]=true;
	}

	for(int m=0;m<M;m++)
	{
		scanf("%d", &party_size[m]);
		party_people[m]=(int *)malloc(party_size[m]*sizeof(int));
		for(int i=0;i<party_size[m];i++)
			scanf("%d", &party_people[m][i]);
		party_root[m]=party_people[m][0];
		for(int i=0;i<party_size[m];i++)
			if(!truth[party_root[m]] && truth[party_people[m][i]])
			{
				union_set(party_people[m][i],party_root[m]);
				party_root[m]=party_people[m][i];
			}
			else
				union_set(party_root[m],party_people[m][i]);

		if(truth[party_root[m]])
			for(int i=0;i<party_size[m];i++)
				truth[party_people[m][i]]=true;
	}

	for(int repeat=0;repeat<M;repeat++)
		for(int m=0;m<M;m++)
			if(!truth[party_root[m]])
				for(int i=0;i<party_size[m];i++)
				{
					if(truth[party_people[m][i]])
					{
						union_set(party_people[m][i],party_root[m]);
						party_root[m]=party_people[m][i];
						for(int j=0;j<party_size[m];j++)
							truth[party_people[m][j]]=true;
						break;
					}
				}
			else
				for(int i=0;i<party_size[m];i++)
					truth[party_people[m][i]]=true;

	for(int m=0;m<M;m++)
		if(!truth[party_root[m]])
			count++;

	printf("%d\n", count);
	free(truth);
	free(party_root);
	free(party);
	for(int m=0;m<M;m++)
		free(party_people[m]);
	free(party_people);
	free(party_size);
	return 0;
}