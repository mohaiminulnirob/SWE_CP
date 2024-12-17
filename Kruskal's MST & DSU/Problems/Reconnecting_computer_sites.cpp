#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=1e6+9;
int parent[N];
int sz[N];
int rk[N];
vector<pair<int,pair<int,int>>>edges;
vector<pair<int,pair<int,int>>>result;
int n,m;
ll cost;
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
            if(find(u)==find(v))
                continue;
            Union(u,v);
            cost+=w;
            result.push_back({w,{u,v}});
            count++;
            // if(count==n-1)
            //     break;
        }
        // if(count<n-1)
        //     impossible=true;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

	int t=0;
	//cin>>t;
	while(cin>>n)
	{
        edges.clear();
        result.clear();
        cost=0;
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({w,{u,v}});
            cost+=w;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({w,{u,v}});
        }
        int x;
        cin>>x;
        for(int i=0;i<x;i++){
            int u,v,w;
            cin>>u>>v>>w;
            //edges.push_back({w,{u,v}});
        }
        //impossible=false;
        ll cost1=cost;
        cost=0;
        kruskals();
        // if(impossible)
        //     cout<<"IMPOSSIBLE"<<'\n';
        if(t!=0)
            cout<<'\n';
        t++;
        cout<<cost1<<'\n'<<cost<<'\n';
	}
    return 0;
}