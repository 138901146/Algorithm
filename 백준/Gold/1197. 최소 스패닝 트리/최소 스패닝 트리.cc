#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int *parent=NULL;

bool compare(tuple<int,int,int> &x,tuple<int,int,int> &y)
{
	return get<2>(x)>get<2>(y);
}

int find_parent(int vertex)
{
	if(parent[vertex]==vertex)
		return vertex;
	return parent[vertex]=find_parent(parent[vertex]);
}

void union_set(int v1,int v2)
{
	if(find_parent(v1)!=find_parent(v2))
		parent[find_parent(v1)]=find_parent(v2);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, A, B, C, count=1, sum=0;
	vector<tuple<int,int,int>> edge;

	cin>>V>>E;

	parent=new int[V+1];

	for(int v=1;v<=V;v++)
		parent[v]=v;

	for(int e=0;e<E;e++)
	{
		cin>>A>>B>>C;
		edge.push_back(make_tuple(A,B,C));
	}

	sort(edge.begin(),edge.end(),compare);

	while(count<V)
	{
		A=get<0>(edge.back());
		B=get<1>(edge.back());
		C=get<2>(edge.back());
		edge.pop_back();

		if(find_parent(A)!=find_parent(B))
		{
			union_set(A,B);
			sum+=C;
			count++;
		}
	}

	cout<<sum<<"\n";
	delete[] parent;
	return 0;
}