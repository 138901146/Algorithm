#include<iostream>
#include<set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x;
	set<int> A;

	cin >> N;
	while(N--)
	{
		cin >> x;
		A.insert(x);
	}

	cin >> M;
	while(M--)
	{
		cin >> x;
		cout << (A.find(x) != A.end()) << '\n';
	}

	return 0;
}