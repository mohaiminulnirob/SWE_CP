#include<bits/stdc++.h>
using namespace std;
long long dis[100005];
bool vis[100005];
long long n,m;
map<long long,vector<pair<long long,long long>>>adjlist;
priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
 
void dijkstra(long long src)
{
    dis[src]=0;
    pq.push(make_pair(dis[src],src));
    while(!pq.empty())
    {
        long long u=pq.top().second;
        pq.pop();
        if(vis[u]==1)
            continue;
        vis[u]=1;
        for(auto child:adjlist[u])
        {
            long long v = child.first;
            long long w = child.second;
 
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push(make_pair(dis[v], v));
            }
        }
 
    }
 
}
 
int main()
{
 
        //adjlist.clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            dis[i]=LLONG_MAX;
            vis[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
 
            adjlist[x].push_back(std:: make_pair(y,z));
        }
 
        dijkstra(1);
        for(int i=1;i<=n;i++)
            cout<<dis[i]<<" ";
    return 0;
}