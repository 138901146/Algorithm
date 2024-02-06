#include<iostream>
#include<vector>
#include<queue>

#define INF 100000000000000

using namespace std;

struct node
{
	int junction;
	long long time;

	bool operator<(const node &b) const
	{
		return time > b.time;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, a, b;
	long long t;

	cin >> N >> M;

	bool sight[N];
	vector<node> adjacent_list[N];
	long long min[N];

	for(int i = 0; i < N; ++i)
		cin >> sight[i];

	while(M--)
	{
		cin >> a >> b >> t;

		if(!sight[a])
			adjacent_list[a].push_back({b, t});
		if(!sight[b])
			adjacent_list[b].push_back({a, t});
	}

	priority_queue<node> pq;
	fill(min + 1, min + N, INF);
	min[0] = 0;
	pq.push({0, 0});

	while(!pq.empty())
	{
		node current = pq.top();
		pq.pop();

		if(current.time != min[current.junction])
			continue;

		for(auto &next: adjacent_list[current.junction])
			if(current.time + next.time < min[next.junction])
			{
				min[next.junction] = current.time + next.time;
				pq.push({next.junction, min[next.junction]});
			}
	}

	min[N - 1] = min[N - 1] == INF ? -1 : min[N - 1];
	cout << min[N - 1];
	return 0;
}