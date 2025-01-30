#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1e5+9;
vector<int>a[N];
int vis[N],par[N],start_node,end_node;
bool found_cycle=false;

void dfs(int node,int parent){
    vis[node]=1;
    for(auto child:a[node]){
        if(child==parent)
        	continue;
        if(vis[child]){
            start_node=child;
            end_node=node;
            found_cycle=true;
            return;
        }
        else{
            par[child]=node;
            dfs(child,node);
            if(found_cycle)
            	return;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,-1);
                if(found_cycle)break;
            }
        }
        if(!found_cycle){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        vector<int>cycle;
        cycle.push_back(start_node);
        int current=end_node;
        while(current!=start_node){
            cycle.push_back(current);
            current=par[current];
        }
        cycle.push_back(start_node);
        reverse(cycle.begin(),cycle.end());

        cout<<cycle.size()<<"\n";
        for(auto node:cycle)
        	cout<<node<<" ";
        cout<<"\n";
    }
    return 0;
}
//https://cses.fi/problemset/task/1669