#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int last_index, value;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, A, length = 0;

	cin >> N;
	vector<node> LIS[N];

	for(int i = 0; i < N; ++i)
	{
		int left = 0, right = length, mid;
		LIS[i].push_back({-1, 2000000000});

		cin >> A;

		while(left < right)
		{
			mid = left + right >> 1;
			if (LIS[mid][LIS[mid].size() - 1].value > A)
				right = mid - 1;
			else if (LIS[mid][LIS[mid].size() - 1].value < A)
				left = mid + 1;
			else
				break;
		}
		right = right < 0 ? 0 : right;
		mid = left + right >> 1;

		if(A <= LIS[mid][LIS[mid].size() - 1].value)
		{
			if(LIS[mid][0].value == 2000000000)
				LIS[mid].clear();
			LIS[mid].push_back({int(mid > 0 ? LIS[mid - 1].size() - 1 : 0), A});
		}
		else
		{
			if(LIS[mid + 1][0].value == 2000000000)
				LIS[mid + 1].clear();
			LIS[mid + 1].push_back({int(LIS[mid].size() - 1), A});
		}

		length += mid == length;
	}

	cout << length << '\n';
	int backtrace[length];

	for(int i = length - 1, index = LIS[i].size() - 1; i >= 0; --i)
	{
		backtrace[i] = LIS[i][index].value;
		index = LIS[i][index].last_index;
	}

	for(int i = 0; i < length; ++i)
		cout << backtrace[i] << ' ';

	return 0;
}