#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cstring>

using namespace std;

int occupied[20001];
vector<int> adjacent_list[20001];
bool visited[20001];

bool dfs(int current)
{
	for(int next:adjacent_list[current])
		if(!visited[next])
		{
			visited[next]=true;

			if(!occupied[next] || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int T;

	cin>>T;

	for(int t=1;t<=T;++t)
	{
		int N, M, K, room=0, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, dk[2]={-1,1}, matched=0;
		char B[50][20][21]={0};
		queue<pair<int,int>> q;
		map<tuple<int,int,int>,int> id;
		set<pair<int,int>> connected;

		cin>>N>>M>>K;

		for(int k=0;k<K;++k)
			for(int n=0;n<N;++n)
				cin>>B[k][n];

		for(int k=0;k<K;++k)
			for(int n=0;n<N;++n)
				for(int m=0;m<M;++m)
					if(B[k][n][m]=='.' && !id[make_tuple(k,n,m)])
					{
						q.push(make_pair(n,m));
						id[make_tuple(k,n,m)]=++room;

						while(!q.empty())
						{
							for(int i=0;i<4;++i)
							{
								int r=q.front().first+dr[i], c=q.front().second+dc[i];

								if(0<=r && r<N && 0<=c && c<M && B[k][r][c]=='.' && !id[make_tuple(k,r,c)])
								{
									id[make_tuple(k,r,c)]=room;
									q.push(make_pair(r,c));
								}
							}

							q.pop();
						}
					}

		for(int i=0;i<20001;++i)
			adjacent_list[i].clear();
		memset(occupied,0,20001*sizeof(int));

		for(int k=0;k<K;++k)
			for(int n=0;n<N;++n)
				for(int m=0;m<M;++m)
				{
					tuple<int,int,int> origin=make_tuple(k,n,m);

					if (id[origin])
						for(int i=0;i<2;++i)
						{
							int next_k=k+dk[i];
							tuple<int,int,int> next=make_tuple(next_k,n,m);

							if(next_k<0 || K<=next_k || !id[next] || connected.contains(make_pair(id[origin],id[next])))
								continue;

							connected.insert(make_pair(id[origin],id[next]));
							connected.insert(make_pair(id[next],id[origin]));
							if (k&1)
								adjacent_list[id[origin]].push_back(id[next]);
							else
								adjacent_list[id[next]].push_back(id[origin]);
						}
				}

		for(int i=1;i<=room;++i)
		{
			memset(visited,0,20001);
			matched+=dfs(i);
		}

		cout<<"Case #"<<t<<": "<<room-matched<<'\n';
	}

	return 0;
}