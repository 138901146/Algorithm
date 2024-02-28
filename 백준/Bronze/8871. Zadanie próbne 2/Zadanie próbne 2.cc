#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	cout << (n + 1 << 1) << ' ' << (n + 1) * 3;
	return 0;
}