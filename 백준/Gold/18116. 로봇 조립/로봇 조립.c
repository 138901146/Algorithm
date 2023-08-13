#include<stdio.h>

int robot[1000001], count[1000001];

int find_robot(int x)
{
	if(robot[x]==x)
		return x;
	return robot[x]=find_robot(robot[x]);
}

void union_parts(int x,int y)
{
	int robot_x=find_robot(x), robot_y=find_robot(y);

	count[robot_x]+=count[robot_y];
	robot[robot_y]=robot_x;
}

int main(void)
{
	int N, x, y;
	char c;

	for(int i=0;i<1000001;i++)
	{
		robot[i]=i;
		count[i]=1;
	}

	scanf("%d", &N);

	while(N--)
	{
		getchar();

		scanf("%c", &c);

		if(c=='I')
		{
			scanf("%d%d", &x, &y);
			if(find_robot(x)!=find_robot(y))
				union_parts(x,y);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", count[find_robot(x)]);
		}
	}

	return 0;
}