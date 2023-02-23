#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int n, current_num=0, current_char=0, number;
	bool *used=NULL, able=true;
	char string[1000000]={'\0', };

	scanf("%d", &n);
	used=(bool *)calloc(n+1,sizeof(bool));

	for(int i=0;i<n&&able;i++)
	{
		scanf("%d", &number);

		if(current_num==number)
		{
			string[current_char++]='-';
			used[number]=true;
		}
		else if(current_num<number)
		{
			while(current_num<number)
			{
				if(!used[current_num])
					string[current_char++]='+';
				current_num++;
			}
			string[current_char++]='-';
			used[number]=true;
		}
		else
		{
			while(used[current_num] && current_num>0)
				current_num--;

			if(current_num!=number)
			{
				able=false;
				break;
			}
			string[current_char++]='-';
			used[number]=true;
		}
		while(current_num>0&&used[current_num])
			current_num--;
	}

	if(able)
		for(int i=0;i<current_char;i++)
			printf("%c\n", string[i]);
	else
		printf("NO\n");
	free(used);
	return 0;
}