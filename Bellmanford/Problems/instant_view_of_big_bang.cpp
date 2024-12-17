#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
#define piii pair<int,pair<int,int>>
#define viii vector<piii>
#define INF 1e9
const int N=1e3+5;
const int mod=1e9+7;
int n,m,node;
map<int,vector<int>>adj;
int dis[N];
bool visited[N];
queue<int>cycle;
vector<int>nodes;

void bellmanford(viii edge) {
    fill(dis,dis+N,INF);
    dis[n]=0;
    int u,v,cost;
    bool terminate=false;
    for(int i=1;i<=n && !terminate;i++){
        terminate=true;
        for(int j=0;j<edge.size();j++){
            u=edge[j].first;
            v=edge[j].second.first;
            cost=edge[j].second.second;
            if(dis[v]>dis[u]+cost) {
                dis[v]=dis[u]+cost;
                terminate=false;
            }
        }
    }
    for(int j=0;j<edge.size();j++){
        u=edge[j].first;
        v=edge[j].second.first;
        cost=edge[j].second.second;
        if(dis[v]>dis[u]+cost) {
            dis[v]=dis[u]+cost;
            cycle.push(v);
            cycle.push(u);
        }
    }
}
void bfs(){
    memset(visited,false,sizeof(visited));
    while(!cycle.empty()){
        int u=cycle.front();
        cycle.pop();
        if(!visited[u])
            nodes.push_back(u);
        visited[u]=true;
        for(int i= 0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(!visited[v])
                cycle.push(v);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    #endif
    
    int t,cs=0;
    cin>>t;
    while(t--){
        cs++;
        cin>>n>>m;
        adj.clear();
        int u,v,w;
        viii edge;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            edge.push_back({v,{u,w}});
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            edge.push_back({n,{i,0}});
            adj[n].push_back(i);
        }
        bellmanford(edge);
        nodes.clear();
        bfs();
        sort(nodes.begin(),nodes.end());
        cout<<"Case "<<cs<<": ";
        if(nodes.empty())
            cout<<"impossible\n";
        else{
            for(int i=0;i<nodes.size();i++)
                cout<<nodes[i]<<" ";
            cout <<'\n';
        }
    }
    return 0;
}