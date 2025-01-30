#include<bits/stdc++.h>
using namespace std;
#define int long long
int level[2005];
int vis[2005];
map<int,vector<int>>adjlist;

void bfs(int x){
	int current;
	queue<int>q;
	q.push(x);
	level[x]=0;
	while(!q.empty() && !vis[x]){
		current=q.front();
		q.pop();
		for(auto u:adjlist[current]){
			if(!vis[u]){
				q.push(u);
				vis[u]=1;
				level[u]=level[current]+1;
			}
			if(u==x)
				break;
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		int x;
    		cin>>x;  
    		if(x==1){
    		  adjlist[i].push_back(j);
    		}
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	memset(vis,0,sizeof(vis));
    	memset(level,0,sizeof(level));
    	bfs(i);
    	if(level[i])
    		cout<<level[i]<<'\n';
    	else cout<<"NO WAY"<<'\n';
    }
    return 0;
}
//https://www.spoj.com/problems/ADACYCLE/
