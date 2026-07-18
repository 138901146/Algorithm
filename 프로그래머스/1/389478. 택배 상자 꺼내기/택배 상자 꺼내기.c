#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int w, int num)
{
    int num_location = (num - 1) % (w * 2), end_location = (n - 1) % (w * 2), num_count = (num - 1) / w, end_count = (n - 1) / w, answer;
    bool num_reversed = w <= num_location, end_reversed = w <= end_location;

    if(num_reversed)
        num_location = w - (num_location - w) - 1;

    if(end_reversed)
    {
        end_location = w - (end_location - w) - 1;

        if(num_location < end_location)
            answer = end_count - num_count;
        else
            answer = end_count + 1 - num_count;
    }
    else
    {
        if(end_location < num_location)
            answer = end_count - num_count;
        else
            answer = end_count + 1 - num_count;
    }

    return answer;
}