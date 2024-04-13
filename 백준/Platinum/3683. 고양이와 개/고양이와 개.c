#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct
{
	int cat_id, dog_id;
}
vote;

int cat_lover_count, dog_lover_count, **adjacent_list=NULL, *adjacent_list_count=NULL, *occupied=NULL;
vote *audience=NULL, *cat_lover=NULL, *dog_lover=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(occupied[next]==-1 || dfs(occupied[next]))
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
	int test_case;

	scanf("%d", &test_case);

	while(test_case--)
	{
		int c, d, v, conflict=0;
		bool *like_cat=NULL;
		char like;

		scanf("%d%d%d", &c, &d, &v);
		audience=(vote *)malloc(v*sizeof(vote));
		like_cat=(bool *)malloc(v*sizeof(bool));
		cat_lover_count=dog_lover_count=0;

		for(int i=0;i<v;++i)
		{
			getchar();
			scanf("%c", &like);

			if(like=='C')
			{
				scanf("%d %c%d", &audience[i].cat_id, &like, &audience[i].dog_id);
				like_cat[i]=true;
				++cat_lover_count;
			}
			else
			{
				scanf("%d %c%d", &audience[i].dog_id, &like, &audience[i].cat_id);
				like_cat[i]=false;
				++dog_lover_count;
			}
		}

		cat_lover=(vote *)malloc(cat_lover_count*sizeof(vote));
		dog_lover=(vote *)malloc(dog_lover_count*sizeof(vote));
		cat_lover_count=dog_lover_count=0;

		for(int i=0;i<v;++i)
			if(like_cat[i])
				cat_lover[cat_lover_count++]=audience[i];
			else
				dog_lover[dog_lover_count++]=audience[i];
		free(audience);
		free(like_cat);

		adjacent_list=(int **)malloc(cat_lover_count*sizeof(int *));
		adjacent_list_count=(int *)calloc(cat_lover_count,sizeof(int));

		for(int i=0;i<cat_lover_count;++i)
			for(int j=0;j<dog_lover_count;++j)
				adjacent_list_count[i]+=cat_lover[i].cat_id==dog_lover[j].cat_id || cat_lover[i].dog_id==dog_lover[j].dog_id;

		for(int i=0;i<cat_lover_count;++i)
		{
			adjacent_list[i]=(int *)malloc(adjacent_list_count[i]*sizeof(int));
			adjacent_list_count[i]=0;
		}

		for(int i=0;i<cat_lover_count;++i)
			for(int j=0;j<dog_lover_count;++j)
				if(cat_lover[i].cat_id==dog_lover[j].cat_id || cat_lover[i].dog_id==dog_lover[j].dog_id)
					adjacent_list[i][adjacent_list_count[i]++]=j;

		occupied=(int *)malloc(dog_lover_count*sizeof(int));
		visited=(bool *)malloc(dog_lover_count*sizeof(bool));

		for(int i=0;i<dog_lover_count;++i)
			occupied[i]=-1;

		for(int i=0;i<cat_lover_count;++i)
		{
			for(int j=0;j<dog_lover_count;++j)
				visited[j]=false;
			conflict+=dfs(i);
		}

		printf("%d\n", v-conflict);
		for(int i=0;i<cat_lover_count;++i)
			free(adjacent_list[i]);
		free(adjacent_list);
		free(adjacent_list_count);
		free(cat_lover);
		free(dog_lover);
		free(occupied);
		free(visited);
	}

	return 0;
}