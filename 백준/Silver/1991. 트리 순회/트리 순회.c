#include<stdio.h>

char child[26][2]={'\0', };

void preorder(int current)
{
	printf("%c", current+'A');
	for(int i=0;i<2;i++)
		if(child[current][i]!='.')
			preorder(child[current][i]-'A');
}

void inorder(int current)
{
	if(child[current][0]!='.')
		inorder(child[current][0]-'A');
	printf("%c", current+'A');
	if(child[current][1]!='.')
		inorder(child[current][1]-'A');

}

void postorder(int current)
{
	for(int i=0;i<2;i++)
		if(child[current][i]!='.')
			postorder(child[current][i]-'A');
	printf("%c", current+'A');
}

int main(void)
{
	int N;
	char p;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		getchar();
		scanf("%c", &p);
		p-='A';

		for(int i=0;i<2;i++)
			scanf(" %c", &child[p][i]);
	}

	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");

	return 0;
}