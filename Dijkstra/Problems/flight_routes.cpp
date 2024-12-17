#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define INF 1e18
const int N=1e5+9;
map<int,vector<pair<ll,ll>>>adjlist;
ll dis[N][11];
ll n,m,k;
void dijkstra(int x){
    dis[x][0]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({dis[x][0],x});
    while(!pq.empty()){
        ll u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(dis[u][k-1]<d)
            continue;
        for(auto v:adjlist[u]){
            if(d+v.second<dis[v.first][k-1]){
                dis[v.first][k-1]=d+v.second;
                pq.push({dis[v.first][k-1],v.first});
                sort(dis[v.first],dis[v.first]+k);
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
    //cin>>t;
    while(t--)
    {
        //memset(vis,0,sizeof(vis));
        adjlist.clear();
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
              dis[i][j]=INF;
        }
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            adjlist[x].pb({y,z});
        }
        dijkstra(1);
        for(int i=0;i<k;i++){
            cout<<dis[n][i]<<" ";
        }
        cout<<'\n';

               
    }
    return 0;
}
