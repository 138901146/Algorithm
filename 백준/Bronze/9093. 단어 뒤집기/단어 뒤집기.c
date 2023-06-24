#include<stdio.h>
#include<string.h>

int main(void)
{
        int T, i, j, k, space=0;
        char word[21], sentence[1001], temp[21];;

        scanf("%d", &T);
        while(getchar()!='\n');

        for(i=0;i<T;i++)
        {
                space=0;
                for(j=0;j<1001;j++)
                        sentence[j]='\0';

                fgets(sentence,sizeof(sentence),stdin);

                for(j=0;;j++)
                {
                        if(sentence[j]==32 || sentence[j]=='\n')
                        {
                                for(k=0;k<21;k++)
                                {
                                        word[k]='\0';
                                        temp[k]='\0';
                                }
                                for(k=space;k<j;k++)
                                        word[k-space]=sentence[k];
                                for(k=0;k<strlen(word);k++)
                                        temp[strlen(word)-k-1]=word[k];
                                for(k=space;k<j;k++)
                                        sentence[k]=temp[k];
                                space=j+1;
                                printf("%s", temp);
                                printf("%c", sentence[j]==32?32:'\n');
                        }
                        if(sentence[j]=='\0')
                                break;
                }
        }

        return 0;
}