#include<iostream>

using namespace std;

int sum[122], cnt[300001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, last;

	cin >> N;

	sum[0] = 0;
	for(last = 1; sum[last - 1] <= N; ++last)
		sum[last] = sum[last - 1] + (last * (last + 1) >> 1);

	--last;
	fill(cnt, cnt + N + 1, 1000000000);
	cnt[0] = 0;

	for(int n = 1; n <= N; ++n)
		for(int i = 1; i < last && sum[i] <= n; ++i)
			cnt[n] = min(cnt[n], cnt[n - sum[i]] + 1);

	cout << cnt[N];

	return 0;
}