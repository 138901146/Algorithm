#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct fireball
{
	int r, c, m, s, d;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K, dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, 1, 1, 1, 0, -1, -1, -1}, sum = 0;
	vector<fireball> alive;

	cin >> N >> M >> K;
	vector<int> status[N][N], del;

	while(M--)
	{
		fireball fb;
		cin >> fb.r >> fb.c >> fb.m >> fb.s >> fb.d;
		--fb.r;
		--fb.c;
		alive.push_back(fb);
	}

	while(K--)
	{
		for(int i = 0; i < alive.size(); ++i)
		{
			alive[i].r += alive[i].s * dr[alive[i].d];
			while(alive[i].r < 0)
				alive[i].r += N;
			alive[i].r %= N;

			alive[i].c += alive[i].s * dc[alive[i].d];
			while(alive[i].c < 0)
				alive[i].c += N;
			alive[i].c %= N;

			status[alive[i].r][alive[i].c].push_back(i);
		}

		for(int r = 0; r < N; ++r)
			for(int c = 0; c < N; ++c)
				if(1 < status[r][c].size())
				{
					int m = 0, s = 0, flag = 0, size = status[r][c].size();

					for(int i = 0; i < size; ++i)
					{
						int index = status[r][c][i];
						m += alive[index].m;
						s += alive[index].s;
						flag |= 1 << (alive[index].d & 1);
						del.push_back(index);
					}

					m /= 5;
					if(m)
					{
						s /= size;

						for(int d = flag == 3; d < 8; d += 2)
							alive.push_back({r, c, m, s, d});
					}
				}

		sort(del.begin(), del.end(), greater<int>());
		for(auto index: del)
			alive.erase(alive.begin() + index);

		for(int r = 0; r < N; ++r)
			for(int c = 0; c < N; ++c)
				status[r][c].clear();
		del.clear();
	}

	for(auto fb: alive)
		sum += fb.m;

	cout << sum;
	return 0;
}