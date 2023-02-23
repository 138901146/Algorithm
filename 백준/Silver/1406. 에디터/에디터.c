#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode
{
	char value;
	struct ListNode *prev;
	struct ListNode *next;
}
ListNode;

ListNode *root=NULL;

ListNode *create_node(char value,ListNode *prev)
{
	ListNode *new_node=(ListNode *)malloc(sizeof(ListNode));

	prev->next=new_node;
	new_node->value=value;
	new_node->prev=prev;
	new_node->next=NULL;

	return new_node;
}

ListNode *delete_node(ListNode *del)
{
	if(del==root)
		return root;

	ListNode *temp=del->prev;

	temp->next=del->next;
	if(del->next!=NULL)
		del->next->prev=temp;

	free(del);
	return temp;
}

ListNode *insert_node(ListNode *current,char value)
{
	ListNode *insert=(ListNode *)malloc(sizeof(ListNode));

	insert->value=value;
	insert->prev=current;
	insert->next=current->next;
	current->next=insert;
	if(insert->next!=NULL)
		insert->next->prev=insert;

	return insert;
}

ListNode *left(ListNode *current)
{
	return current==root?current:current->prev;
}

ListNode *right(ListNode *current)
{
	return current->next==NULL?current:current->next;
}

void print_root()
{
	root=root->next;

	while(root!=NULL)
	{
		printf("%c", root->value);
		root=root->next;
	}
}

int main(void)
{
	char str[100001]={'\0', }, command, value;
	ListNode *current=NULL;
	int N, len;

	scanf("%s", str);
	len=strlen(str);

	root=(ListNode *)malloc(sizeof(ListNode));
	root->value='\0';
	current=create_node(str[0],root);
	for(int i=1;i<len;i++)
		current=create_node(str[i],current);

	scanf("%d", &N);
	getchar();

	for(int n=0;n<N;n++)
	{
		scanf("%c", &command);

		switch(command)
		{
			case 'L':
				current=left(current);
				break;
			case 'D':
				current=right(current);
				break;
			case 'B':
				current=delete_node(current);
				break;
			case 'P':
				getchar();
				scanf("%c", &value);
				current=insert_node(current,value);
				break;
		}
		getchar();
	}

	print_root();
	return 0;
}