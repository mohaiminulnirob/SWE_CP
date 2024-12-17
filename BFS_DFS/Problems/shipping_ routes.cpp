#include<bits/stdc++.h>
using namespace std;
#define int long long
map<string,int>vis;
map<string,int>level;
map<string,vector<string>>adjlist;

void bfs(string start){
	string current;
	queue<string>q;
	q.push(start);
	vis[start]=1;
	level[start]=0;
	while(!q.empty()){
		current=q.front();
		q.pop();
		for(auto u:adjlist[current]){
			if(!vis[u]){
				vis[u]=1;
				q.push(u);
				level[u]=level[current]+1;
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
    cout<<"SHIPPING ROUTES OUTPUT\n\n";
	int t;
	cin>>t;
	int cs=0;
	while(t--)
	{
		cs++;
		cout<<"DATA SET  "<<cs<<'\n'<<'\n';
		adjlist.clear();
        int n,m,p;
        cin>>n>>m>>p;
        for(int i=0;i<n;i++)
        {
        	string s;
        	cin>>s;
        }
        for(int i=0;i<m;i++){
        	string a,b;
        	cin>>a>>b;
        	adjlist[a].push_back(b);
        	adjlist[b].push_back(a);
        }

        for(int i=0;i<p;i++)
        {
        	vis.clear();
		    level.clear();
        	string a,b;
        	int sz;
        	cin>>sz>>a>>b;
        	bfs(a);
        	if(!vis[b])
        		cout<<"NO SHIPMENT POSSIBLE"<<'\n';
        	else{

        		int answer=level[b]*sz*100;
                cout<<'$'<<answer<<'\n';
        	}
        }
        cout<<'\n';
 
        if(!t)
        	cout<<"END OF OUTPUT\n";

	}
	return 0;
}