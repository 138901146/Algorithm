#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;

bool compare_by_weight(pair<int, int> x, pair<int, int> y) {
    return get<0>(x) > get<0>(y);
}

struct compare
{
    bool operator()(pair<int, int> &x,pair<int, int> &y) {
        return x.second < y.second;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, M, V;
    long long max=0;
    vector<pair<int,int>> jewel;

    cin>>N>>K;
    int *C=new int[K];
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;

    for(int n=0;n<N;n++)
    {
        cin>>M>>V;
        jewel.push_back(make_pair(M,V));
    }
    for(int k=0;k<K;k++)
        cin>>C[k];

    sort(C,C+K);
    sort(jewel.begin(),jewel.end(), compare_by_weight);

    for(int k=0;k<K;k++)
    {
        while(!jewel.empty())
            if(jewel.back().first<=C[k]) {
                pq.push({jewel.back().first, jewel.back().second});
                jewel.pop_back();
            }
            else
                break;
        if(!pq.empty()) {
            max += pq.top().second;
            pq.pop();
        }
    }

    cout<<max<<"\n";
    delete[] C;
    return 0;
}