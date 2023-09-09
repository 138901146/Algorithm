#include <stdio.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int *solution(int lottos[],size_t lottos_len,int win_nums[],size_t win_nums_len)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int *answer=malloc(2*sizeof(int)), count=0, zero_count=0;

    qsort((void *)lottos,(size_t)lottos_len,sizeof(int),compare);
    qsort((void *)win_nums,(size_t)win_nums_len,sizeof(int),compare);

    for(int i=0;lottos[i]==0;i++,zero_count++);

    for(int i=0,j=0;i<lottos_len&&j<win_nums_len;)
        if(lottos[i]<win_nums[j])
            i++;
        else if(lottos[i]>win_nums[j])
            j++;
        else
        {
            i++;
            j++;
            count++;
        }
    
    answer[0]=(count+zero_count)>0?7-count-zero_count:6;
    answer[1]=count>0?7-count:6;
    
    return answer;
}