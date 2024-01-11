#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> meeting[100000];

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, count=0, last=-1;

	cin >> N;

	for(int n=0; n < N; ++n)
		cin >> meeting[n].first >> meeting[n].second;
	sort(meeting, meeting + N, compare);

	for(int n=0; n < N; ++n)
		if(meeting[n].first >= last)
		{
			++count;
			last=meeting[n].second;
		}

	cout << count;

	return 0;
}