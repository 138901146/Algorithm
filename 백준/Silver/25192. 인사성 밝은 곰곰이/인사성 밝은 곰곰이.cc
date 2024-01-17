#include<iostream>
#include<set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, count = 0;
	string chat;
	set<string> user;

	cin >> N;

	while(N--)
	{
		cin >> chat;

		if(chat == "ENTER")
		{
			count += user.size();
			user.clear();
		}
		else
			user.insert(chat);
	}

	cout << count + user.size();
	return 0;
}