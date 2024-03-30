#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

long long N, P, Q, X, Y;
map<long long, long long> A;

long long calculate_A(long long i)
{
	return i <= 0 ? 1 : A[i] ? A[i] : A[i] = calculate_A(i / P - X) + calculate_A(i / Q - Y);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> P >> Q >> X >> Y;

	cout << calculate_A(N);

	return 0;
}