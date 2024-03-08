#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

struct order
{
	int count;
	string name;

	bool operator<(const order &b) const
	{
		return count == b.count ? name < b.name : count > b.count;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, count = 0;
	string name;
	map<string, int> name_to_index;
	vector<order> book;

	cin >> N;

	while(N--)
	{
		cin >> name;

		if(name_to_index.find(name) == name_to_index.end())
		{
			name_to_index[name] = count++;
			book.push_back({0, name});
		}

		++book[name_to_index[name]].count;
	}

	sort(book.begin(), book.end());

	cout << book[0].name;
	return 0;
}