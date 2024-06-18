#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		int N, M, R, count = 0;
		set<int> pair;

		cin >> N >> M;

		while(N--)
		{
			cin >> R;

			if(M < R << 1)
			{
				if(pair.find(R) != pair.end())
					++count;
			}
			else
				pair.insert(M - R);
		}

		cout << "Case #" << t << ": " << count << '\n';
	}

	return 0;
}