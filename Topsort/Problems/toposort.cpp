#include<bits/stdc++.h>
using namespace std;

bool acyclic=true;;
vector<int>adj[10005];
vector<int> visited;
vector<int> ans;

void dfs(int v) {
    visited[v]=1;
    for (auto u : adj[v]) {
        if (!visited[u])
            dfs(u);
        else if(visited[u]==1)
            acyclic=false;
    }
    visited[v] = 2;
    ans.push_back(v);
}

void topological_sort(int n) {
    visited.assign(n+1, false);
    ans.clear();
    for (int i = n; i >=1;i--){

        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end(),greater<int>());
    }

    topological_sort(n);
    if(acyclic==false)
        cout<<"Sandro fails."<<endl;
    else{

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    }
    return 0;
}
