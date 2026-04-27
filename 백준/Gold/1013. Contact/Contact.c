#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	int T;
	bool q[10]={false, false, false, true, false, false, false, true, true, false};

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int state=0;
		char str[201]={'\0', };

		scanf("%s", str);

		for(int i=0;i<strlen(str);i++)
			switch(state)
			{
				case 0:
						state=str[i]=='0'?1:4;
						break;
				case 1:
						state=str[i]=='0'?2:3;
						break;
				case 3:
						state=str[i]=='0'?1:4;
						break;
				case 4:
						state=str[i]=='0'?5:2;
						break;
				case 5:
						state=str[i]=='0'?6:2;
						break;
				case 6:
						state=str[i]=='0'?6:7;
						break;
				case 7:
						state=str[i]=='0'?1:8;
						break;
				case 8:
						state=str[i]=='0'?9:8;
						break;
				case 9:
						state=str[i]=='0'?6:3;
						break;
				default:
						break;
			}

		printf("%s\n", q[state]?"YES":"NO");
	}

	return 0;
}