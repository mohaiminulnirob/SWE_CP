#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
map<int,vector<pi>>adjlist;
vector<int>dis;
vector<bool>vis;
int n;

void dijkstra(int src){
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    pq.push({0,src});
    dis[src] = 0;

    while (!pq.empty()){
        int u=pq.top().second;
        int u_dist=pq.top().first;
        pq.pop();

        if(vis[u]) 
            continue;
        vis[u]=true;

        for (auto& edge:adjlist[u]){
            int v=edge.first;
            int weight=edge.second;

            if(dis[u]+ weight<dis[v]){
                dis[v]=dis[u]+weight;
                pq.push({dis[v],v});
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    cin>>n;
    adjlist.clear();
    dis.assign(n+1,LLONG_MAX);
    vis.assign(n+1,false);
    for (int i=2;i<=n;i++){
        for (int j=1;j<i;j++){
            string x;
            cin>>x;
            if(x!="x"){
                int weight=stoll(x);
                adjlist[i].push_back({j,weight});
                adjlist[j].push_back({i,weight});
            }
        }
    }

    dijkstra(1);
    int max_dist=0;
    for (int i=2;i<=n;i++){
        max_dist=max(max_dist,dis[i]);
    }
    cout<<max_dist<<'\n';
    return 0;
}
