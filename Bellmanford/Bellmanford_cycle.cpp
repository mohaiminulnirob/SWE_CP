#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,node;
int graph[2000][3];
int dis[1000];
int parent[1000];
bool impossible;
void bellmanford(int src){
	for(int i=0;i<n;i++)
	{
		dis[i]=INT_MAX;
	}
	dis[src]=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			if(dis[graph[j][0]]!=INT_MAX && dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]]){
				dis[graph[j][1]]=dis[graph[j][0]]+graph[j][2];
				parent[graph[j][1]]=graph[j][0];
			}
		}
	}
	for(int j=0;j<m;j++){
		if(dis[graph[j][0]]!=INT_MAX && dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]]){
            node=graph[j][1];
            parent[graph[j][1]]=graph[j][0];
			impossible=true;
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

	int t;
	cin>>t;
	while(t--)
	{
		impossible=false;
        cin>>n>>m;
        for(int i=0;i<m;i++){
        	int x,y,z;
        	cin>>x>>y>>z;
        	graph[i][0]=x;
        	graph[i][1]=y;
        	graph[i][2]=z;
        }
        bellmanford(0);
        if(impossible){
        	cout<<"possible"<<'\n';
        	vector<int>cycle;
        	for(int v=node;;v=parent[v]){
        		cycle.push_back(v);
        		if(v==node && cycle.size()>1)
        			break;
        	}
            reverse(cycle.begin(),cycle.end());
            for(auto u:cycle){
            	cout<<u<<" ";
            }
            cout<<"\n";
        }
        else cout<<"not possible"<<'\n';
        
	}
	return 0;
}
/*
BellmanFord

Instant view of big bang(5L lightoj)
Extended traffic(1AB- lightoj)
Wormholes(1AC- uva)
High score(cses)
cycle finding(cses)?

dense graph not suitable
sparse graph suitable
*/