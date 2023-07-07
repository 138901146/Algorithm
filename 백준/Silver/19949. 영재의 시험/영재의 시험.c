#include<stdio.h>

int answer[10], selected[10];

int find_max_score(int number)
{
	if(number==10)
	{
		int sum=0;

		for(int i=0;i<10;i++)
			sum+=answer[i]==selected[i];

		return sum>=5;
	}

	int count=0;

	if(number<2)
		for(int i=1;i<6;i++)
		{
			selected[number]=i;
			count+=find_max_score(number+1);
		}
	else
		for(int i=1;i<6;i++)
			if(selected[number-2]!=selected[number-1] || selected[number-2]!=i || selected[number-1]!=i)
			{
				selected[number]=i;
				count+=find_max_score(number+1);
			}

	return count;
}
	
int main(void)
{
	for(int i=0;i<10;i++)
		scanf("%d", &answer[i]);

	printf("%d\n", find_max_score(0));
	return 0;
}