#include<bits/stdc++.h>
using namespace std;

#define N 200009
#define ll long long

int parent[N];
int sz[N];
int rk[N];
vector<pair<int,pair<int,int>>>edg;
vector<pair<int,pair<int,int>>>res;
int n,m;
ll cost;
bool imp;

void mk(int v){
    parent[v]=v;
    sz[v]=1;
    rk[v]=0;
}
int find(int v){
    if(v==parent[v])
    	return v;
    return parent[v]=find(parent[v]);
}
void connect(int a,int b){
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
            mk(i);
        }
     
    

    sort(edg.begin(),edg.end());
    int count=0;
        for(auto e:edg){
             int w=e.first;
            int u=e.second.first;
            int v=e.second.second;
            if(find(u)==find(v)){
                //cout<<"!"<<'\n';
                continue;
            }
            connect(u,v);
            cost+=w;
            res.push_back({w,{u,v}});
            count++;
    
        }
        //cout<<count<<'\n';
        if(count<n-1)
            imp=true;
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
        edg.clear();
        res.clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++){
        	mk(i);
        }
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edg.push_back({w,{u,v}});
        }
        imp=false;
        cost=0;
        kruskals();
        //cout<<cost<<'\n';
        if(imp)
            cout<<"imp"<<'\n';
        else cout<<cost<<'\n';
	}
    return 0;
}