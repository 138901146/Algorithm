#include<stdio.h>
#include<string.h>

char number[41]={0};

int is_two_valid(int index)
{
	return number[index-1]!='0'&&10*(number[index-1]-'0')+number[index]-'0'<35;
}

int main(void)
{
	int card[40]={0}, length;

	scanf("%s", number);

	length=strlen(number);
	card[0]=number[0]!='0';
	for(int i=1;i<length;++i)
	{
		card[i]=number[i]=='0'?0:card[i-1];
		if(is_two_valid(i))
			card[i]+=1<i?card[i-2]:1;
	}

	printf("%d", card[length-1]);
	return 0;
}