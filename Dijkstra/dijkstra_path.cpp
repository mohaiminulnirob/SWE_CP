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
int n,m;
void dijkstra(int x){
	dis[x]=0;
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push({dis[x],x});
	while(!pq.empty()){
		int u=pq.top().second;
		vis[u]=1;
		pq.pop();
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
	//cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		adjlist.clear();
		memset(par,0,sizeof(par));
		cin>>n>>m;
		for(int i=1;i<=n;i++)
        {
           dis[i]=INF;
        }
		for(int i=0;i<m;i++){
			int x,y,z;
			cin>>x>>y>>z;
         adjlist[x].pb({y,z});
         adjlist[y].pb({x,z});
		}
		int src=1;
		dijkstra(src);
		if(!par[n]){
			cout<<"-1"<<'\n';
			break;
		}
		int p=n;
      vector<int>v;
      v.pb(p);
      while(1){
      	p=par[p];
      	v.pb(p);
      	if(p==1)
      		break;
      }
      reverse(v.begin(),v.end());
      for(auto u:v)
      	cout<<u<<" ";
      cout<<'\n';        
	}
	return 0;
}
/*
Dijkstra

Dijkstra? (5A -cf)
Shortest Routes I(cses)
The shortest path(5Q spoj)
Country road(1Y lightoj)
Brush(1Z lightoj)
Number maze(1AA uva)
Easy Dijkstra problem(3I spoj)
MPI Maelstrom(lab final 1D-UVA)
Bicycle(cf)
Flight discount(cses)
Flight routes(lab final 1A-cses)
*/