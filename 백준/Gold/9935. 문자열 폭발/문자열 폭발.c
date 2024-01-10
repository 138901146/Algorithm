#include<stdio.h>

typedef struct
{
	int index, order, continuous;
}
structure;

char str[1000001]={'\0'}, compare[37]={'\0'}, answer[1000001]={'\0'};
int top=0, table[123], str_length=0, compare_length=0, deleted_count=0, answer_length=0;
structure stack[1000001];

int main(void)
{
	scanf("%s", str);
	scanf("%s", compare);

	for(int i=0;i<123;++i)
		table[i]=-1;

	for(int i=0;compare[i]!='\0';++i)
		table[compare[i]]=compare_length++;

	for(int i=0;str[i]!='\0';++i)
	{
		answer[answer_length++]=str[str_length++];
		if(table[str[i]]!=-1)
		{
			if(top==0)
			{
				if(table[str[i]]==0)
				{
					stack[0].index=i;
					stack[0].order=table[str[i]];
					stack[0].continuous=1;
					++top;
				}
			}
			else
			{
				if(table[str[i]]==0)
				{
					stack[top].index=i;
					stack[top].order=table[str[i]];
					stack[top].continuous=1;
					++top;
				}
				else if(stack[top-1].order==table[str[i]]-1)
				{
					stack[top].index=i;
					stack[top].order=table[str[i]];
					stack[top].continuous=stack[top-1].continuous+1;
					++top;
				}
				else
					top=0;
			}

			if(stack[top-1].continuous==compare_length)
			{
				top-=compare_length;
				deleted_count+=compare_length;
				answer_length-=compare_length;
			}
		}
		else
			top=0;
	}

	if(deleted_count==str_length)
		printf("FRULA");
	else
		for(int i=0;i<answer_length;++i)
			printf("%c", answer[i]);

	return 0;
}