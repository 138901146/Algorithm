#include<iostream>
#include<set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, element, total, count = 0;
	set<int> s;

	cin >> A >> B;
	total = A + B;
	
	while(A--)
	{
		cin >> element;
		s.insert(element);
	}

	while(B--)
	{
		cin >> element;
		count += s.find(element) != s.end();
	}

	cout << total - (count << 1);

	return 0;
}