#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=205;
bool acyclic=true;
map<int,vector<int>>adj;
map<string,int>mp;
vector<int>visited;
vector<int>ans;

void topologicalSort(int V){
    vector<int>indegree(V,0);
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<V;i++) {
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.top();
        q.pop();
        ans.pb(node);

        for(auto it:adj[node]){
            indegree[it]--; 
            if(indegree[it]==0)
                q.push(it);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    int n,cs=0;
    while(cin>>n){
        cs++;
        mp.clear();
        adj.clear();
        ans.clear();
        string s[n+1];
        for(int i=0;i<n;i++){
            cin>>s[i];
            mp[s[i]]=i;
        }
        int m;
        cin>>m;
        while(m--){
            string x,y;
            cin>>x>>y;
            adj[mp[x]].pb(mp[y]);
        }
        topologicalSort(n);
        cout<<"Case #"<<cs<<": Dilbert should drink beverages in this order:";
        for(auto u:ans){
            cout<<" "<<s[u];
        }
        cout<<"."<<'\n'<<'\n';
    }
    return 0;
}
