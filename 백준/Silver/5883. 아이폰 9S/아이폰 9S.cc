#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, max = 1;
	set<int> viewed;

	cin >> N;

	int B[N];

	for(int i = 0; i < N; ++i)
		cin >> B[i];

	for(int i = 0; i < N; ++i)
	{
		if(viewed.find(B[i]) != viewed.end())
			continue;

		viewed.insert(B[i]);

		int last = B[0], count = 1;

		for(int j = 1; j < N; ++j)
			if(B[i] == B[j])
				continue;
			else if(B[j] == last)
			{
				++count;
				max = count < max ? max : count;
			}
			else
			{
				count = 1;
				last = B[j];
			}
	}

	cout << max;
	return 0;
}