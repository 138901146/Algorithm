#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(void)
{
	int M, x, w, cmd;
	map<int,int> locker;
	vector<int> answer;

	cin>>M;

	while(M--)
	{
		cin>>cmd;

		if(cmd==1)
		{
			cin>>x>>w;
			locker[w]=x;
		}
		else
		{
			cin>>w;
			answer.push_back(locker[w]);
		}
	}

	for(int i=0;i<answer.size();++i)
		cout<<answer[i]<<'\n';
	return 0;
}