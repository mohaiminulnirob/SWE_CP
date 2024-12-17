#include<bits/stdc++.h>
using namespace std;
#define int long long
#define min -1e18
int n,m,node;
int graph[5005][3];
int dis[2505];
int parent[2505];
bool impossible;

void bellmanford(int src){
	dis[src]=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			if(dis[graph[j][0]]!=min && dis[graph[j][0]]+graph[j][2]>dis[graph[j][1]]){
				dis[graph[j][1]]=dis[graph[j][0]]+graph[j][2];
				parent[graph[j][1]]=graph[j][0];
			}
		}
	}
	for(int j=0;j<m;j++){
		if(dis[graph[j][0]]!=min && dis[graph[j][0]]+graph[j][2]>dis[graph[j][1]]){
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
 
	int t=1;
	//cin>>t;
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
        for(int i=1;i<=n;i++)
	    {
		 dis[i]=min;
	    }
        bellmanford(1);
        if(impossible){
        	cout<<"-1"<<'\n';
        	
        }
        else cout<<dis[n]<<'\n';
        
	}
	return 0;
}