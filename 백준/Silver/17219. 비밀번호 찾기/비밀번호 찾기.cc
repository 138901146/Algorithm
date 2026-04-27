#include<iostream>
#include<map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	string domain, password;
	map<string, string> notepad;

	cin >> N >> M;

	while(N--)
	{
		cin >> domain >> password;
		notepad[domain] = password;
	}

	while(M--)
	{
		cin >> domain;
		cout << notepad[domain] << '\n';
	}

	return 0;
}