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

		set<string>::iterator marathoner = participant.find(name);
		if(marathoner == participant.end())
			participant.insert(name);
		else
			participant.erase(marathoner);
	}

	cout << *participant.begin();
	return 0;
}