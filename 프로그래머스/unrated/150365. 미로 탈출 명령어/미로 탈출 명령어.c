#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* solution(int m, int n, int y, int x, int c, int r, int k) {
    int width=r-x, height=c-y, distance=abs(width)+abs(height), count=0, left=0, right=0, down=0, up=0, current[2]={x,y};
    char* answer=NULL;
    
    if(distance>k || (distance&1)!=(k&1))
    {
        answer=(char *)calloc(11,sizeof(char));
        strcpy(answer,"impossible");
        return answer;
    }
    //dlru
    answer=(char *)calloc(k+1,sizeof(char));

    if(width<0)
        left=-width;
    else
        right=width;
    if(height<0)
        up=-height;
    else
        down=height;
    
    if(distance<k && ((k-distance)>>1)+y+down<=m)
    {
        up+=(k-distance)>>1;
        down+=(k-distance)>>1;
    }
    else if(distance<k)
    {
        up+=m-(y+down);
        down+=m-(y+down);
        int add_more=(k-(up+down+left+right))>>1;
        left+=add_more;
        right+=add_more;
    }
    
    while(count<k)
        if(down>0 && current[1]<m)
        {
            answer[count++]='d';
            current[1]++;
            down--;
        }
        else if(left>0 && current[0]>1)
        {
            answer[count++]='l';
            current[0]--;
            left--;
        }
        else if(right>0 && current[0]<n)
        {
            answer[count++]='r';
            current[0]++;
            right--;
        }
        else if(up>0 && current[1]>1)
        {
            answer[count++]='u';
            current[1]--;
            up--;
        }
        else
        {
            free(answer);
            answer=(char *)calloc(11,sizeof(char));
            strcpy(answer,"impossible");
            return answer;
        }
    
    return answer;
}