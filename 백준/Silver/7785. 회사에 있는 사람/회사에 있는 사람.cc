#include<iostream>
#include<set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string name, operation;
	set<string, greater<string>> in;

	cin >> n;

	while(n--)
	{
		cin >> name >> operation;

		if(operation == "enter")
			in.insert(name);
		else
			in.erase(name);
	}

	for(auto x: in)
		cout << x << '\n';

	return 0;
}