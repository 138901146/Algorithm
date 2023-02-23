#include<stdio.h>
#include<stdlib.h>

void password(char *alphabet,int C,int L,int current,int last,char *list,int consonant,int vowel)
{
	if(current==L)
	{
		if(consonant>1 && vowel>0)
		{
			for(int l=0;l<L;l++)
				printf("%c", list[l]);
			printf("\n");
		}
		return;
	}
	for(int i=last+1;i<C;i++)
	{
		list[current]=alphabet[i];
		if(alphabet[i]=='a' || alphabet[i]=='e' || alphabet[i]=='i' || alphabet[i]=='o' || alphabet[i]=='u')
			password(alphabet,C,L,current+1,i,list,consonant,vowel+1);
		else
			password(alphabet,C,L,current+1,i,list,consonant+1,vowel);
	}
}

int main(void)
{
	int L, C;
	char *alphabet=NULL,  *list=NULL;

	scanf("%d%d", &L, &C);
	alphabet=(char *)malloc(C*sizeof(char));
	list=(char *)calloc(L,sizeof(char));

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

	password(alphabet,C,L,0,-1,list,0,0);
	free(alphabet);
	return 0;
}