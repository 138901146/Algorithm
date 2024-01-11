#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	int index, value;

	bool operator<(const node &b)const
	{
		return value>b.value;
	}
};

struct ordered_node
{
	int index, order, value;

	bool operator<(const ordered_node &b)const
	{
		return value>b.value;
	}
};

int fox[4001], wolf[4001][2], INF=1000000000;
vector<node> adjacent_list[4001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, a, b, d;

	cin >> N >> M;

	for(int m=0;m<M;++m)
	{
		cin >> a >> b >> d;
		adjacent_list[a].push_back({b, d});
		adjacent_list[b].push_back({a, d});
	}

	for(int n=1;n<=N;++n)
		fox[n]=wolf[n][0]=wolf[n][1]=INF;

	priority_queue<node> fox_pq;
	fox[1]=0;
	fox_pq.push({1,0});

	while(!fox_pq.empty())
	{
		node current=fox_pq.top();
		fox_pq.pop();

		if(fox[current.index]!=current.value)
			continue;

		for(node next:adjacent_list[current.index])
			if(fox[next.index]>current.value+(next.value<<1))
			{
				fox[next.index]=current.value+(next.value<<1);
				fox_pq.push({next.index,fox[next.index]});
			}
	}

	priority_queue<ordered_node> wolf_pq;
	wolf[1][0]=0;
	wolf_pq.push({1,0,0});

	while(!wolf_pq.empty())
	{
		ordered_node current=wolf_pq.top();
		wolf_pq.pop();

		if(wolf[current.index][current.order]!=current.value)
			continue;

		for(node next:adjacent_list[current.index])
			if(current.order)
			{
				if (wolf[next.index][0] > current.value + (next.value<<2))
				{
					wolf[next.index][0] = current.value + (next.value<<2);
					wolf_pq.push({next.index, 0, wolf[next.index][0]});
				}
			}
			else
			{
				if (wolf[next.index][1] > current.value + next.value)
				{
					wolf[next.index][1] = current.value + next.value;
					wolf_pq.push({next.index, 1, wolf[next.index][1]});
				}
			}
	}

	int count=0;
	for(int n=2;n<=N;++n)
		count+=fox[n]<min(wolf[n][0],wolf[n][1]);
	cout << count;

	return 0;
}