#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct
{
	int level, count, matched[300];
}
room;

char n[300][17]={0};

int compare(const void *x,const void *y)
{
	return strcmp(n[*(int *)x],n[*(int *)y]);
}

int main(void)
{
	int p, m, l[300], room_count=0;
	room queue[300]={0};

	scanf("%d%d", &p, &m);

	for(int i=0;i<p;++i)
	{
		bool matched=false;

		scanf("%d%s", &l[i], n[i]);

		for(int j=0;j<room_count;++j)
			if(queue[j].level-10<=l[i]&&l[i]<=queue[j].level+10&&queue[j].count<m)
			{
				queue[j].matched[queue[j].count++]=i;
				matched=true;
				break;
			}

		if(!matched)
		{
			queue[room_count].level=l[i];
			queue[room_count].count=1;
			queue[room_count].matched[0]=i;
			++room_count;
		}
	}

	for(int i=0;i<room_count;++i)
	{
		qsort((void *)queue[i].matched,(size_t)queue[i].count,sizeof(int),compare);

		printf("%s!\n", queue[i].count==m?"Started":"Waiting");
		for(int j=0;j<queue[i].count;++j)
			printf("%d %s\n", l[queue[i].matched[j]], n[queue[i].matched[j]]);
	}

	return 0;
}