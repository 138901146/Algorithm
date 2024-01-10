#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct
{
	int index, order, continuous;
}
structure;

char str[1000001]={'\0'}, compare[37]={'\0'};
int top=0, table[123], str_length, compare_length, deleted_count=0;
structure stack[1000001];
bool deleted[1000001]={false};

int main(void)
{
	scanf("%s", str);
	scanf("%s", compare);

	str_length=strlen(str);
	compare_length=strlen(compare);

	for(int i=0;i<123;++i)
		table[i]=-1;

	for(int i=0;i<compare_length;++i)
		table[compare[i]]=i;

	for(int i=0;i<str_length;++i)
	{
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
				for(int j=0;j<compare_length;++j)
					deleted[stack[top-1-j].index]=true;
				top-=compare_length;
				deleted_count+=compare_length;
			}
		}
		else
			top=0;
	}

	if(deleted_count==str_length)
		printf("FRULA");
	else
		for(int i=0;i<str_length;++i)
			if(!deleted[i])
				printf("%c", str[i]);

	return 0;
}