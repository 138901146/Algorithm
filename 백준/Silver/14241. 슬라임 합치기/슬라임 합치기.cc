#include<iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, x, y, score = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	while(N--)
	{
		cin >> x;
		pq.push(x);
	}

	while(pq.size() > 1)
	{
		x = pq.top();
		pq.pop();
		y = pq.top();
		pq.pop();
		score += x * y;
		pq.push(x + y);
	}

	cout << score;
	return 0;
}