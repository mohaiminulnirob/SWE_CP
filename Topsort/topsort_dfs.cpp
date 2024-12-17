#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool acyclic=true;
map<int,vector<int>>adj;
vector<int>visited;
vector<int>ans;

void dfs(int v){
    visited[v]=1;
    for(auto u:adj[v]){
        if(!visited[u])
            dfs(u);
        else if(visited[u]==1)
            acyclic=false;
    }
    visited[v]=2;
    ans.pb(v);
}
void topological_sort(int n){
    visited.assign(n+1,false);
    ans.clear();
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(),ans.end());
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    adj.clear();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
      adj[x].pb(y);
    }
    topological_sort(n);
    if(acyclic==false)
      cout<<"IMPOSSIBLE"<<endl;
    else{
      for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
      }
      cout<<'\n';
    }
    return 0;
}
/*
Topological Sorting(kahn, dfs(cycle detection))

Course schedule(2M-cses)
Longest Flight Route(2N-cses)
Beverages(5H-uva)(kahn)
Topological Sorting(SPOJ)
*/