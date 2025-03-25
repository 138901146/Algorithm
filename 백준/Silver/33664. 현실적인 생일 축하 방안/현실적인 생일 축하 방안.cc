#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int main(void)
{
	int N, M;
	long long B, p, total=0;
	string i, j;
	map<string,long long> item;

	cin>>B>>N>>M;

	while(N--)
	{
		cin>>i>>p;
		item.insert({i,p});
	}

	while(M--)
	{
		cin>>j;
		total+=item[j];
	}

	if(total<=B)
		cout<<"acceptable";
	else
		cout<<"unacceptable";
	return 0;
}