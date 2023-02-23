#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef int element;
typedef struct DlistNode
{
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
}
DlistNode;

void init(DlistNode *phead)
{
	phead->llink=phead;
	phead->rlink=phead;
	phead->data=-1;
}

void push_front(DlistNode *before,DlistNode *new_node)
{
	while(before->llink->data!=-1)
		before=before->llink;

	new_node->llink=before->llink;
	new_node->rlink=before;

	before->llink->rlink=new_node;
	before->llink=new_node;
}

void push_back(DlistNode *before,DlistNode *new_node)
{
	while(before->rlink->data!=-1)
		before=before->rlink;

	new_node->llink=before;
	new_node->rlink=before->rlink;

	before->rlink->llink=new_node;
	before->rlink=new_node;
}

void dremove_node(DlistNode *phead_node,DlistNode *removed)
{
	if(removed==phead_node)
		return;

	removed->llink->rlink=removed->rlink;
	removed->rlink->llink=removed->llink;

	free(removed);
}

int pop_front(DlistNode *phead_node)
{
	int N=phead_node->rlink->data;

	dremove_node(phead_node,phead_node->rlink);
	return N;
}

int pop_back(DlistNode *phead_node)
{
	int N=phead_node->llink->data;

	dremove_node(phead_node,phead_node->llink);
	return N;
}

int front(DlistNode *phead_node)
{
	return phead_node->rlink->data;
}

int back(DlistNode *phead_node)
{
	return phead_node->llink->data;
}

int main(void)
{
	DlistNode head_node, **deque=NULL;
	int N, size=0, num;

	scanf("%d", &N);
	while(getchar()!='\n');

	deque=(DlistNode **)malloc(sizeof(DlistNode *)*N);
	init(&head_node);

	for(int i=0;i<N;i++)
	{
		char command[30]={'\0', };

		fgets(command,sizeof(command),stdin);
		deque[i]=(DlistNode *)malloc(sizeof(DlistNode));

		if(strncmp(command,"push_front",10)==0)
		{
			for(int j=11;command[j]!='\0';j++)
				command[j-11]=command[j];

			deque[i]->data=atoi(command);
			push_front(&head_node,deque[i]);
			size++;
		}
		else if(strncmp(command,"push_back",9)==0)
		{
			for(int j=10;command[j]!='\0';j++)
				command[j-10]=command[j];

			deque[i]->data=atoi(command);
			push_back(&head_node,deque[i]);
			size++;
		}
		else if(strncmp(command,"pop_front",9)==0)
		{
			num=pop_front(&head_node);
			printf("%d\n", num);
			free(deque[i]);
			size-=num!=-1;
		}
		else if(strncmp(command,"pop_back",8)==0)
		{
			num=pop_back(&head_node);
			printf("%d\n", num);
			free(deque[i]);
			size-=num!=-1;
		}
		else if(strncmp(command,"size",4)==0)
		{
			printf("%d\n", size);
			free(deque[i]);
		}
		else if(strncmp(command,"front",5)==0)
		{
			printf("%d\n", front(&head_node));
			free(deque[i]);
		}
		else if(strncmp(command,"back",4)==0)
		{
			printf("%d\n", back(&head_node));
			free(deque[i]);
		}
		else if(strncmp(command,"empty",5)==0)
		{
			printf("%d\n", size==0);
			free(deque[i]);
		}
		else
		{
			printf("error\n");
			free(deque[i]);
		}
	}

	return 0;
}