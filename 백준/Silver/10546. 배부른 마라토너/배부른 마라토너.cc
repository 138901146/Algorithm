#include<iostream>
#include<set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string name;
	set<string> participant;

	cin >> N;

	N = (N << 1) - 1;
	while(N--)
	{
		cin >> name;

		if(participant.find(name) == participant.end())
			participant.insert(name);
		else
			participant.erase(name);
	}

	cout << *participant.begin();
	return 0;
}