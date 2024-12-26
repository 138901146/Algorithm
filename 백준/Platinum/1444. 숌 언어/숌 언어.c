#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<memory.h>

int adjacent_list[1352][2500], adjacent_list_count[1352]={0}, occupied[1352];
bool visited[1352];

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
	int length, fixed=2, flag, id[2500], matched=0;
	char str[2501]={0};

	scanf("%s", str);
	length=strlen(str);

	flag='a'<=str[0]&&str[0]<='z';
	for(int i=0;i<length-1;++i,flag^=1)
		id[i]=flag?(str[i]-'a')*26+str[i+1]-'A':(str[i]-'A')*26+str[i+1]-'a'+676;

	fixed-=id[0]==id[length-2];
	for(int i=1;i<length-3;++i)
		if(id[i]!=id[0] && id[i]!=id[length-2] && id[i+1]!=id[0] && id[i+1]!=id[length-2])
		{
			adjacent_list[id[i]][adjacent_list_count[id[i]]++]=id[i+1];
			adjacent_list[id[i+1]][adjacent_list_count[id[i+1]]++]=id[i];
		}

	memset(occupied,-1,1352*sizeof(int));
	for(int i=0;i<676;++i)
	{
		memset(visited,0,1352);
		matched+=dfs(i);
	}

	printf("%d", fixed+matched);
	return 0;
}