#include<iostream>
#include<vector>
#include<algorithm>
#include <map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    string pokemon[N+1];
    map<string, int> index;

    for(int i=1;i<=N;++i)
    {
        cin >> pokemon[i];
        index.insert({pokemon[i], i});
    }

    string query;
    while(M--)
    {
        cin >> query;

        if(isdigit(query[0]))
            cout << pokemon[stoi(query)] << '\n';
        else
            cout << index[query] << '\n';
    }

	return 0;
}