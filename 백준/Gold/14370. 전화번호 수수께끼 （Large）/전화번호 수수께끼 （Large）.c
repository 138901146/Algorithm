#include<stdio.h>
#include<string.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=1;t<=T;t++)
	{
		char S[2001]={'\0', };
		int alphabet[26]={0, }, number[10]={0, };

		scanf("%s", S);
		for(int s=0;s<strlen(S);s++)
			alphabet[S[s]-'A']++;

		if(alphabet['Z'-'A']>0)
		{
			number[0]=alphabet['Z'-'A'];
			alphabet['Z'-'A']-=number[0];
			alphabet['E'-'A']-=number[0];
			alphabet['R'-'A']-=number[0];
			alphabet['O'-'A']-=number[0];
		}
		if(alphabet['W'-'A']>0)
		{
			number[2]=alphabet['W'-'A'];
			alphabet['T'-'A']-=number[2];
			alphabet['W'-'A']-=number[2];
			alphabet['O'-'A']-=number[2];
		}
		if(alphabet['U'-'A']>0)
		{
			number[4]=alphabet['U'-'A'];
			alphabet['F'-'A']-=number[4];
			alphabet['O'-'A']-=number[4];
			alphabet['U'-'A']-=number[4];
			alphabet['R'-'A']-=number[4];
		}
		if(alphabet['X'-'A']>0)
		{
			number[6]=alphabet['X'-'A'];
			alphabet['S'-'A']-=number[6];
			alphabet['I'-'A']-=number[6];
			alphabet['X'-'A']-=number[6];
		}
		if(alphabet['G'-'A']>0)
		{
			number[8]=alphabet['G'-'A'];
			alphabet['E'-'A']-=number[8];
			alphabet['I'-'A']-=number[8];
			alphabet['G'-'A']-=number[8];
			alphabet['H'-'A']-=number[8];
			alphabet['T'-'A']-=number[8];

		}
		if(alphabet['T'-'A']>0)
		{
			number[3]=alphabet['T'-'A'];
			alphabet['T'-'A']-=number[3];
			alphabet['H'-'A']-=number[3];
			alphabet['R'-'A']-=number[3];
			alphabet['E'-'A']-=2*number[3];
		}
		if(alphabet['F'-'A']>0)
		{
			number[5]=alphabet['F'-'A'];
			alphabet['F'-'A']-=number[5];
			alphabet['I'-'A']-=number[5];
			alphabet['V'-'A']-=number[5];
			alphabet['E'-'A']-=number[5];
		}
		if(alphabet['S'-'A']>0)
		{
			number[7]=alphabet['S'-'A'];
			alphabet['S'-'A']-=number[7];
			alphabet['E'-'A']-=2*number[7];
			alphabet['V'-'A']-=number[7];
			alphabet['N'-'A']-=number[7];
		}
		if(alphabet['O'-'A']>0)
		{
			number[1]=alphabet['O'-'A'];
			alphabet['O'-'A']-=number[1];
			alphabet['N'-'A']-=number[1];
			alphabet['E'-'A']-=number[1];
		}
		if(alphabet['I'-'A']>0)
		{
			number[9]=alphabet['I'-'A'];
			alphabet['N'-'A']-=2*number[9];
			alphabet['I'-'A']-=number[9];
			alphabet['E'-'A']-=number[9];
		}

		printf("Case #%d: ", t);
		for(int i=0;i<10;i++)
			for(int j=0;j<number[i];j++)
				printf("%d", i);
		printf("\n");
	}

	return 0;
}