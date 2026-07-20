#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// schedules_len은 배열 schedules의 길이입니다.
// timelogs_rows는 2차원 배열 timelogs의 행 길이, timelogs_cols는 2차원 배열 timelogs의 열 길이입니다.
int solution(int schedules[], size_t schedules_len, int** timelogs, size_t timelogs_rows, size_t timelogs_cols, int startday) {
    int answer = 0;

    for(int worker = 0; worker < schedules_len; ++worker)
    {
        int hope = (schedules[worker] / 100) * 60 + (schedules[worker] % 100), today = startday;
        bool reward = true;
        
        for(int days = 0; days < 7; ++days, ++today)
        {
            int real = (timelogs[worker][days] / 100) * 60 + (timelogs[worker][days] % 100);

            if(5 < today)
            {
                if(today == 7)
                    today = 0;
                continue;
            }

            if(hope + 10 < real)
            {
                reward = false;
                break;
            }
        }

        answer += reward;
    }

    return answer;
}