#include <iostream>
#include <vector>

using namespace std;

bool a[100001];
vector<int> vertex[100001], red[100001], blue[100001];
long long query[100001];

void dfs(int parent, int index)
{
	int v = vertex[parent][index];

	red[parent][index] = a[v];
	blue[parent][index] = a[v] ^ 1;

	for(int i = 0; i < vertex[v].size(); ++i)
		if(vertex[v][i] != parent)
		{
			if(red[v][i] == -1)
				dfs(v, i);

			red[parent][index] += red[v][i];
			blue[parent][index] += blue[v][i];
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, u, v, Q, red_count = 0, blue_count;

	cin >> N;

	for(int n = 1; n <= N; ++n)
	{
		cin >> a[n];
		red_count += a[n];
		query[n] = -1;
	}
	blue_count = N - red_count;

	for(int n = 1; n < N; ++n)
	{
		cin >> u >> v;

		red[u].push_back(-1);
		blue[u].push_back(-1);
		red[v].push_back(-1);
		blue[v].push_back(-1);
		vertex[u].push_back(v);
		vertex[v].push_back(u);
	}

	cin >> Q;

	while(Q--)
	{
		cin >> u;

		if(query[u] == -1)
		{
			query[u] = 0;

			for(int i = 0; i < vertex[u].size(); ++i)
			{
				if(red[u][i] == -1)
					dfs(u, i);

				query[u] += (long long)(red_count - a[u] - red[u][i]) * blue[u][i] + (long long)(blue_count - (a[u] ^ 1) - blue[u][i]) * red[u][i];
			}

			query[u] >>= 1;
		}

		cout << query[u] << '\n';
	}

	return 0;
}