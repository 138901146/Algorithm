#include<stdio.h>
#include<string.h>

int main(void)
{
	int N, m[4], food[15][5], min=100000000, list[15], length=0;
	char ans[22]={'\0', };

	scanf("%d", &N);
	for(int i=0;i<4;i++)
		scanf("%d", &m[i]);

	for(int n=0;n<N;n++)
		for(int i=0;i<5;i++)
			scanf("%d", &food[n][i]);

	for(int i=1;i<(1<<N);i++)
	{
		int intake[4]={0, }, sum=0, able=1;

		for(int j=0;j<N;j++)
			if(i&(1<<j))
			{
				for(int k=0;k<4;k++)
					intake[k]+=food[j][k];
				sum+=food[j][4];
			}

		for(int j=0;j<4;j++)
			if(intake[j]<m[j])
			{
				able=0;
				break;
			}

		if(able)
		{
			if(sum<min)
			{
				min=sum;
				length=0;
				int count=0;
				for(int j=0;j<22;j++)
					ans[j]='\0';

				for(int j=0;j<N;j++)
					if(i&(1<<j))
					{
						list[length++]=j+1;
						if(j<9)
							ans[count++]=j+'1';
						else
						{
							ans[count++]='1';
							ans[count++]='9'-(j-9);
						}
					}
			}
			else if(sum==min)
			{
				int count=0, length_temp=0, list_temp[15];
				char temp[22]={'\0', };

				for(int j=0;j<N;j++)
					if(i&(1<<j))
					{
						list_temp[length_temp++]=j+1;
						if(j<9)
							temp[count++]=j+'1';
						else
						{
							temp[count++]='1';
							temp[count++]='9'-(j-9);
						}
					}
				if(strcmp(ans,temp)>0)
				{
					strcpy(ans,temp);
					length=length_temp;
					for(int j=0;j<length;j++)
						list[j]=list_temp[j];
				}
			}
		}
	}

	if(min==100000000)
		printf("-1\n");
	else
	{
		printf("%d\n", min);
		for(int i=0;i<length;i++)
			printf("%d ", list[i]);
		printf("\n");
	}
	return 0;
}