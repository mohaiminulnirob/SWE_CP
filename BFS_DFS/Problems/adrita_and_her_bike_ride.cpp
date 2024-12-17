#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define INF 1e18
const int N=1e5+9;
map<int,vector<pair<int,ll>>>adjlist;
ll dis[N];
int vis[N];
int par[N];
int n,m,src,des;
void dijkstra(int x){
    dis[x]=0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({dis[x],x});
    while(!pq.empty()){
        int u=pq.top().second;
         pq.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(auto v:adjlist[u]){
            if(dis[u]+v.second<dis[v.first]){
                dis[v.first]=dis[u]+v.second;
                par[v.first]=u;
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

    int t=1;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        adjlist.clear();
        memset(par,0,sizeof(par));
        cin>>n>>m>>src>>des;
        for(int i=1;i<=n;i++)
        {
           dis[i]=INF;
        }
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            adjlist[x].pb({y,z+12});
            adjlist[y].pb({x,z+12});
        }
        
        dijkstra(src);
        cout<<dis[des]<<'\n';

               
    }
    return 0;
}
