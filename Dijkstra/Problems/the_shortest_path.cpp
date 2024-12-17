#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=2e5+9;
map<int,vector<pair<int,int>>>adjlist;
map<string,int>m;
int dis[10005];
int n;
void dijkstra(int x,int s){
   for(int i=1;i<=n;i++)
   	dis[i]=INT_MAX;
	dis[x]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({dis[x],x});
	while(!pq.empty()){
		int u=pq.top().second;
		if(u==s)
			break;
		pq.pop();
		for(auto v:adjlist[u]){
			if(dis[u]+v.second<dis[v.first]){
				dis[v.first]=dis[u]+v.second;
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
		adjlist.clear();
		m.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			m[s]=i;
			int nodes;
			cin>>nodes;
			while(nodes--){
				int x,y;
				cin>>x>>y;
				adjlist[i].pb({x,y});
			}
		}

     int q;
     cin>>q;
     while(q--){
     	string x,y;
     	cin>>x>>y;
     	int r=m[x];
     	int s=m[y];
     	dijkstra(r,s);
     	cout<<dis[s]<<'\n';
     } 
	}
	return 0;
}