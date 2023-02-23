#include<stdio.h>

char tree_info[26][3]={'\0', };

void preorder(int current)
{
	printf("%c", current+'A');

	if(tree_info[current][1]!='\0')
		preorder(tree_info[current][1]-'A');
	if(tree_info[current][2]!='\0')
		preorder(tree_info[current][2]-'A');
}

void inorder(int current)
{
	if(tree_info[current][1]!='\0')
		inorder(tree_info[current][1]-'A');
	printf("%c", current+'A');
	if(tree_info[current][2]!='\0')
		inorder(tree_info[current][2]-'A');
}

void postorder(int current)
{
	if(tree_info[current][1]!='\0')
		postorder(tree_info[current][1]-'A');
	if(tree_info[current][2]!='\0')
		postorder(tree_info[current][2]-'A');
	printf("%c", current+'A');
}

int main(void)
{
	int N;
	char parent, child[2];

	scanf("%d", &N);

	getchar();
	for(int n=0;n<N;n++)
	{
		scanf("%c", &parent);
		getchar();
		for(int i=0;i<2;i++)
		{
			scanf("%c", &child[i]);
			getchar();

			if(child[i]!='.')
			{
				tree_info[parent-'A'][i+1]=child[i];
				tree_info[child[i]-'A'][0]=parent;
			}
		}
	}

	for(int i=0;i<N;i++)
		if(tree_info[i][0]=='\0')
		{
			preorder(i);
			printf("\n");
			inorder(i);
			printf("\n");
			postorder(i);
			printf("\n");
		}

	return 0;
}