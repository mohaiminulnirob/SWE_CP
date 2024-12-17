#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+9;
int parent[N];
int sz[N];
int rk[N];
int connectedComponents=0,msize=0;
void make(int v){
    parent[v]=v;
    sz[v]=1;
    rk[v]=1;
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
        connectedComponents--;
    	if(rk[b]>rk[a])
    		swap(a,b);
    	parent[b]=a;
    	sz[a]+=sz[b];
        if(sz[a]>msize)
            msize=sz[a];
        if(rk[b]==rk[a])
            rk[a]++;
    }
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
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
        	make(i);
        }
        connectedComponents=n;
        msize=1;
        while(k--){
        	int u,v;
        	cin>>u>>v;
        	Union(u,v);
        	cout<<connectedComponents<<" "<<msize<<'\n';
        }
        // for(int i=1;i<=n;i++){
        // 	if(parent[i]==i){
        // 		connectedComponents++;
        // 		if(sz[i]>msize)
        // 			msize=sz[i];
        // 	}
        // }
        // cout<<connectedComponents<<" "<<msize<<'\n';
	}
	return 0;
}