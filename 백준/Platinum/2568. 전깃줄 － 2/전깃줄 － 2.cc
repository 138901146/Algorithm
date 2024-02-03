#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

struct edge
{
	int A, B;
};

bool compare(const edge &x, const edge &y)
{
	return x.A < y.A;
}

struct node
{
	int last_index, value;
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, length = 0;

	cin >> N;
	edge pole[N];
	vector<node> LIS[N];
	map<int, int> b_to_a;

	for (int i = 0; i < N; ++i)
	{
		cin >> pole[i].A >> pole[i].B;
		b_to_a[pole[i].B] = pole[i].A;
	}

	sort(pole, pole + N, compare);

	for (int i = 0; i < N; ++i)
	{
		int left = 0, right = length, mid;
		LIS[i].push_back({-1, 2000000000});

		while (left < right)
		{
			mid = left + right >> 1;
			if (LIS[mid][LIS[mid].size() - 1].value > pole[i].B)
				right = mid - 1;
			else if (LIS[mid][LIS[mid].size() - 1].value < pole[i].B)
				left = mid + 1;
			else
				break;
		}
		right = right < 0 ? 0 : right;
		mid = left + right >> 1;

		if (pole[i].B <= LIS[mid][LIS[mid].size() - 1].value)
		{
			if (LIS[mid][0].value == 2000000000)
				LIS[mid].clear();
			LIS[mid].push_back({int(mid > 0 ? LIS[mid - 1].size() - 1 : 0), pole[i].B});
		}
		else
		{
			if (LIS[mid + 1][0].value == 2000000000)
				LIS[mid + 1].clear();
			LIS[mid + 1].push_back({int(LIS[mid].size() - 1), pole[i].B});
		}

		length += mid == length;
	}

	cout << N - length;
	set<int> selected;

	for (int i = length - 1, index = LIS[i].size() - 1; i >= 0; --i)
	{
		selected.insert(b_to_a[LIS[i][index].value]);
		index = LIS[i][index].last_index;
	}

	for (int i = 0; i < N; ++i)
		if (!selected.contains(pole[i].A))
			cout << '\n' << pole[i].A;
	return 0;
}