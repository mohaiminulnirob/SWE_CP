#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

bool vis[maxN];
int dis[maxN],p[maxN],ans[maxN],indegree[maxN];
int V,E;
map<int,vector<int>>adj;

void dfs(int start)
{
    vis[start]=1;
    for(auto child: adj[start])
    {
        if(vis[child]!=1)
        {
            dfs(child);
        }
    }
}
void modified_topo()
{
    queue<int> q;

    for (int i = 1; i <= V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
    
        for (auto child: adj[node]) {
            if(dis[node] != -1 && dis[child] < dis[node]+1){
                dis[child] = dis[node] + 1;
                p[child] = node;
            }
            indegree[child]--;
        
            if (indegree[child] == 0)
                q.push(child);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  

    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    dfs(1);
    if(!vis[V])
    {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    modified_topo();
    int n=dis[V]-dis[1];
    cout<<n+1<<'\n';
    for(int i = n, u = V; i >= 0; i--){
        ans[i] = u;
        u = p[u];
    }
    for(int i=0;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<'\n';

    return 0;
}
