#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    int digit[10]={0};
    long long answer = 0;
    
    while(n)
    {
        ++digit[n%10];
        n/=10;
    }
    
    for(int i=9;i>=0;--i)
        for(int j=0;j<digit[i];++j)
        {
            answer*=10;
            answer+=i;
        }
    
    return answer;
}