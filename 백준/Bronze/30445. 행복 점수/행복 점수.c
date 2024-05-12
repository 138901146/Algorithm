#include<stdio.h>
#include<math.h>

int main(void)
{
	float H=0, G=0;
	char message[2000]={0};
	int index=0;

	fgets(message,sizeof(message),stdin);

	while(message[index]!=0)
		switch(message[index++])
		{
			case 'H':
			case 'P':
			case 'Y':
				H+=1;
				break;
			case 'S':
			case 'D':
				G+=1;
				break;
			case 'A':
				H+=1;
				G+=1;
				break;
			default:
				break;
		}

	printf("%.2f", H==0&&G==0?50:round(10000*H/(H+G))/100);
	return 0;
}