#include<stdio.h>
#include<string.h>

int main(void)
{
	int n, old[3], young[3], birth[3];
	char oldest[16]={'\0', }, youngest[16]={'\0', }, name[16]={'\0', };

	scanf("%d", &n);

	scanf("%s", name);
	strcpy(oldest, name);
	strcpy(youngest, name);
	for(int i=0;i<3;++i)
	{
		scanf("%d", &birth[i]);
		old[i]=young[i]=birth[i];
	}

	while(--n)
	{
		scanf("%s%d%d%d", name, &birth[0], &birth[1], &birth[2]);

		if(birth[2]<old[2])
		{
			for(int i=0;i<3;++i)
				old[i]=birth[i];
			strcpy(oldest, name);
		}
		else if(birth[2]==old[2])
		{
			if(birth[1]<old[1])
			{
				for(int i=0;i<3;++i)
					old[i]=birth[i];
				strcpy(oldest, name);
			}
			else if(birth[1]==old[1] && birth[0]<old[0])
			{
				for(int i=0;i<3;++i)
					old[i]=birth[i];
				strcpy(oldest, name);
			}
		}

		if(birth[2]>young[2])
		{
			for(int i=0;i<3;++i)
				young[i]=birth[i];
			strcpy(youngest, name);
		}
		else if(birth[2]==young[2])
		{
			if(birth[1]>young[1])
			{
				for(int i=0;i<3;++i)
					young[i]=birth[i];
				strcpy(youngest, name);
			}
			else if(birth[1]==young[1] && birth[0]>young[0])
			{
				for(int i=0;i<3;++i)
					young[i]=birth[i];
				strcpy(youngest, name);
			}
		}
	}

	printf("%s\n%s", youngest, oldest);
	return 0;
}