#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define INF 2147483647

using namespace std;

struct edge
{
	int a, b, c;
	bool blocked;
};

struct node
{
	int country;
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

	int N, M, target;

	cin >> N >> M;
	edge route[M];
	vector<int> adjacent_list[N + 1];
	int previous[N + 1];
	node min[N + 1];
	priority_queue<node> pq;

	for(int m = 0; m < M; ++m)
	{
		cin >> route[m].a >> route[m].b >> route[m].c;
		adjacent_list[route[m].a].push_back(m);
		adjacent_list[route[m].b].push_back(m);
		route[m].blocked = false;
	}

	for(int n = 1; n <= N; ++n)
	{
		min[n].country = n;
		min[n].time = INF;
	}
	min[1].time = 0;
	pq.push(min[1]);

	while(!pq.empty())
	{
		node current = pq.top();
		pq.pop();

		if(min[current.country].time != current.time)
			continue;

		for(auto index: adjacent_list[current.country])
		{
			target = route[index].a == current.country ? route[index].b : route[index].a;

			if(current.time + route[index].c < min[target].time)
			{
				min[target].time = current.time + route[index].c;
				previous[target] = index;
				pq.push(min[target]);
			}
		}
	}

	target = N;
	while(target != 1)
	{
		int index = previous[target];
		route[index].blocked = true;
		target = route[index].a == target ? route[index].b : route[index].a;
	}

	for(int n = 2; n <= N; ++n)
		min[n].time = INF;
	pq.push(min[1]);

	while(!pq.empty())
	{
		node current = pq.top();
		pq.pop();

		if(min[current.country].time != current.time)
			continue;

		for(auto index: adjacent_list[current.country])
		{
			if(route[index].blocked)
				continue;

			target = route[index].a == current.country ? route[index].b : route[index].a;

			if(current.time + route[index].c < min[target].time)
			{
				min[target].time = current.time + route[index].c;
				pq.push(min[target]);
			}
		}
	}

	cout << min[N].time;
	return 0;
}