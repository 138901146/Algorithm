#include<iostream>
#include<map>

using namespace std;

map<int,long long> pizza;

long long get_fun(int x)
{
	return x<2?0:pizza[x]?pizza[x]:pizza[x]=(long long)(x>>1)*(x-(x>>1))+get_fun(x>>1)+get_fun(x-(x>>1));
}

int main(void)
{
	int N;

	cin>>N;

	cout<<get_fun(N);
	return 0;
}	