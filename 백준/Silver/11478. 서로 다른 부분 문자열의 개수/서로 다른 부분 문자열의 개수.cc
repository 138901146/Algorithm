#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	set<string> diff;
	cin >> S;

	for(int i = 0; i < S.size(); ++i)
		for(int j = 0; j <= i; ++j)
			diff.insert(S.substr(j, i - j + 1));

	cout << diff.size();
	return 0;
}