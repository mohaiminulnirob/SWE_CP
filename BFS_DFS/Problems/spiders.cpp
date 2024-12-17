#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,vector<int>>adjlist;
int vis[105];
int level[105];

int bfs(int x){
	int current,lev=0;
	queue<int>q;
	q.push(x);
	vis[x]=1;
	level[x]=0;
	while(!q.empty()){
		current=q.front();
		q.pop();
		for(auto u:adjlist[current]){
			if(!vis[u]){
				q.push(u);
				vis[u]=1;
				level[u]=level[current]+1;
				lev=level[u];
			}

		}

	}
	return lev;
}


int bfs1(int x){
	int current,tnode;
	queue<int>q;
	q.push(x);
	vis[x]=1;
	while(!q.empty()){
		current=q.front();
		q.pop();
		for(auto u:adjlist[current]){
			if(!vis[u]){
				q.push(u);
				vis[u]=1;
				tnode=u;
			}

		}

	}
	return tnode;
}



int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	//#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //#endif

	int n;
	cin>>n;
	int tlevel=0;
	for(int i=0;i<n;i++){
		adjlist.clear();
		memset(vis,0,sizeof vis);
		int V;
		cin>>V;
		for(int j=0;j<V-1;j++)
		{
			int x,y;
			cin>>x>>y;
			adjlist[x].push_back(y);
			adjlist[y].push_back(x);
		}
		int tnode=bfs1(1);
		memset(vis,0,sizeof (vis));
		memset(level,0,sizeof (level));
		tlevel=tlevel+bfs(tnode);
	}
	cout<<tlevel<<'\n';
} 