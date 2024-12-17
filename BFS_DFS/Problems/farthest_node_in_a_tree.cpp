#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=3e4+9;
map<int,vector<pair<int,int>>>adjlist;
int vis[N][2];
int tnode,current;

int bfs(int start,int mdis)
{
    queue<int>q;
    q.push(start);
    vis[start][0]=1;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        for(auto child:adjlist[current])
        {
            if(vis[child.first][0]!=1)
            {
            q.push(child.first);
            vis[child.first][0]=1;
            vis[child.first][1]=vis[current][1]+child.second;
            if(vis[child.first][1]>=mdis)
            {
                mdis=vis[child.first][1];
                tnode=child.first;
            }

            }
        }
    }
    return tnode;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int t,cs=0;
    cin>>t;
    while(t--)
    {
        cs++;
        memset(vis,0,sizeof(vis));
        adjlist.clear();
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adjlist[u].pb({v,w});
            adjlist[v].pb({u,w});
        }
        int node1=bfs(0,0);
        memset(vis,0,sizeof(vis));
        int node2=bfs(node1,0);
        int ans=vis[node2][1];
       cout<<"Case "<<cs<<": "<<ans<<endl;
    }
    return 0;
}
