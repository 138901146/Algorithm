#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, alphabet[26]={0, };
	bool five=false;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		char name[31]={'\0', };

		scanf("%s", name);

		alphabet[name[0]-'a']++;

		if(alphabet[name[0]-'a']>=5)
			five=true;
	}

	if(five)
	{
		for(int i=0;i<26;i++)
			if(alphabet[i]>=5)
				printf("%c", 'a'+i);
		printf("\n");
	}
	else
		printf("PREDAJA\n");

	return 0;
}