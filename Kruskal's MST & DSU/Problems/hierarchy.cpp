#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int parent[N];
int vis[1005];
int sz[N];
int rk[N];
vector<pair<int,pair<int,int>>>edges;
vector<pair<int,pair<int,int>>>result;
int n,m;
long long cost;
bool impossible;

void make(int v){
    parent[v]=v;
    sz[v]=1;
    rk[v]=0;
}
int find(int v){
    if(v==parent[v])
    	return v;
    return parent[v]=find(parent[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
    	if(rk[b]>rk[a])
    		swap(a,b);
    	parent[b]=a;
    	sz[a]+=sz[b];
        if(rk[b]==rk[a])
            rk[a]++;
    }
}
void kruskals(){
    for(int i=1;i<=n;i++){
            make(i);
        }
     
    sort(edges.begin(),edges.end());
    int count=0;
        for(auto e:edges){
            int w=e.first;
            int u=e.second.first;
            int v=e.second.second;
            if(find(u)==find(v) || vis[v])
                continue;
            Union(u,v);
            vis[v]=1;
            cost+=w;
            result.push_back({w,{u,v}});
            count++;
        }
        if(count<n-1)
            impossible=true;
}
int main()
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
        edges.clear();
        result.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
        }
        for(int i=1;i<=n;i++){
        	make(i);
        }
        cin>>m;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({w,{u,v}});
        }
        impossible=false;
        cost=0;
        kruskals();
        if(impossible)
            cout<<"-1"<<'\n';
        else cout<<cost<<'\n';
	}
    return 0;
}