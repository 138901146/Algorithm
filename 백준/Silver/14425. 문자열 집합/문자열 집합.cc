#include<iostream>
#include <set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int N, M, count=0;
    set<string> S;
    string str;

    cin >> N >> M;

    while(N--)
    {
        cin >> str;
        S.insert(str);
    }

    while(M--)
    {
        cin >> str;
        count+=S.find(str)!=S.end();
    }

    cout << count;
	return 0;
}