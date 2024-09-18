#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	char password[21]={0};

	scanf("%s", password);

	while(strcmp(password,"end"))
	{
		bool acceptable=true, vowel=false;
		int con=0, vow=0, length=strlen(password);

		if(password[0]=='a' || password[0]=='e' || password[0]=='i' || password[0]=='o' || password[0]=='u')
		{
			vowel=true;
			vow=1;
		}
		else
			con=1;

		for(int i=1;i<length && acceptable;++i)
		{
			if(password[i]==password[i-1] && password[i]!='e' && password[i]!='o')
				acceptable=false;

			if(password[i]=='a' || password[i]=='e' || password[i]=='i' || password[i]=='o' || password[i]=='u')
			{
				vowel=true;
				con=0;
				if(2<++vow)
					acceptable=false;
			}
			else
			{
				vow=0;
				if(2<++con)
					acceptable=false;
			}
		}

		printf("<%s> is %s.\n", password, vowel&&acceptable?"acceptable":"not acceptable");
		memset(password,0,21);
		scanf("%s", password);
	}

	return 0;
}