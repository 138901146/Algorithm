#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	int N, count=1;
	string A, B;
	set<string> dance;

	cin >> N;

	dance.insert("ChongChong");
	while(N--)
	{
		cin >> A >> B;
		if(dance.contains(A) && !dance.contains(B))
		{
			++count;
			dance.insert(B);
		}
		else if(dance.contains(B) && !dance.contains(A))
		{
			++count;
			dance.insert(A);
		}
	}

	cout << count;
	return 0;
}