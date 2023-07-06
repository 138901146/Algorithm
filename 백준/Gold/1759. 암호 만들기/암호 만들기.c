#include<stdio.h>

int vowel[2]={0, }, L, C, order[15];
char alphabet[16]={'\0', };

void find_password(int index,int start)
{
	if(index==L)
	{
		if(vowel[0]>1 && vowel[1]>0)
		{
			for(int i=0;i<index;i++)
				printf("%c", alphabet[order[i]]);
			printf("\n");
		}
		return;
	}

	int check[26]={0, };

	for(int i=0;i<index;i++)
		check[alphabet[order[i]]-'a']=1;

	for(int c=start;c<C;c++)
		if(check[alphabet[c]-'a']==0)
		{
			int is_vowel=alphabet[c]=='a'||alphabet[c]=='e'||alphabet[c]=='i'||alphabet[c]=='o'||alphabet[c]=='u';

			vowel[is_vowel]++;
			order[index]=c;
			find_password(index+1,c+1);
			vowel[is_vowel]--;
		}
}

int main(void)
{
	scanf("%d%d", &L, &C);

	for(int c=0;c<C;c++)
	{
		getchar();
		scanf("%c", &alphabet[c]);
	}

	for(int i=0;i<C;i++)
		for(int j=i+1;j<C;j++)
			if(alphabet[i]>alphabet[j])
			{
				char temp=alphabet[i];
				alphabet[i]=alphabet[j];
				alphabet[j]=temp;
			}

	find_password(0,0);
	return 0;
}