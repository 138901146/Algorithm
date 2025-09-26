#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	char str[11]={0}, compare[100][21]={0};
	int N, count=0, length;

	scanf("%s", str);
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%s", compare[i]);

	length=strlen(str);
	for(int i=0;i<N;++i)
	{
		bool found=false;
		int compare_length=strlen(compare[i]);

		for(int j=0;j<compare_length;++j)
			compare[i][j+compare_length]=compare[i][j];

		for(int j=0;j<compare_length&&!found;++j)
		{
			found=true;
			for(int k=0;k<length;++k)
				if(str[k]!=compare[i][j+k])
				{
					found=false;
					break;
				}
		}

		count+=found;
	}

	printf("%d", count);
	return 0;
}