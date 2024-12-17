#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
map<int,vector<pair<int,int>>>adjlist;
int dis[505];
int vis[505];
int n,m;
void dijkstra(int x){
    dis[x]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dis[x],x});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto v:adjlist[u]){
         if(max(dis[u],v.second)<dis[v.first]){
            dis[v.first]=max(dis[u],v.second);
            pq.push({dis[v.first],v.first});
         }
      }

    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int t;
    cin>>t;
    int cs=0;
    while(t--)
    {
        cs++;
        memset(vis,0,sizeof(vis));
        adjlist.clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
           dis[i]=INT_MAX;
        }
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            x++;
            y++;
            adjlist[x].push_back({y,z});
            adjlist[y].push_back({x,z});
        }
        int src;
        cin>>src;
        src++;
        dijkstra(src);
        cout<<"Case "<<cs<<": "<<endl;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]!=INT_MAX)
                 cout<<dis[i]<<endl;
            else cout<<"Impossible"<<endl;
        }
        
    }
    return 0;
}
