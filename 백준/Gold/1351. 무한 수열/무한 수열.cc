#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

long long N, P, Q;
map<long long, long long> A;

long long calculate_A(long long x)
{
	return A[x] ? A[x] : A[x] = calculate_A(x / P) + calculate_A(x / Q);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> P >> Q;
	A[0] = 1;

	cout << calculate_A(N);

	return 0;
}