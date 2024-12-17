#include<bits/stdc++.h>
using namespace std;
 
const int max_node = 100009;
int ans[max_node];
int scc_count=0,nv=0;
map<int,vector<int>> graph;
map<int,vector<int>> transpose_graph;
bool vis[max_node];
stack<int> st;
 
void dfs(int n){
    if(vis[n]) return;
 
    int len=graph[n].size();
    vis[n]=true;
 
    for(int i= 0; i<len; i++){
        dfs(graph[n][i]);
    }
    st.push(n);
}
 
void dfs_ans(int n){
    if(vis[n] == true) return;
 
    ans[n]=scc_count+1;
 
    int len= transpose_graph[n].size();
    vis[n]= true;
 
    for(int i= 0; i<len; i++){
        dfs_ans(transpose_graph[n][i]);
    }
}
 
int kosarajuSCC(int numberOfNodes){
    dfs(1);
    for(int i=1;i<=numberOfNodes;i++)
    {
        if(!vis[i])
        {
            nv=i;
            break;
        }
    }
    for(int i=2; i<=numberOfNodes; i++){
        if(vis[i] == false){
            dfs(i);
        }
    }
    for(int i=1; i<=numberOfNodes; i++){
        vis[i]=false;
    }
 
    while(!st.empty()){
        if(vis[st.top()] == false){
            dfs_ans(st.top());
            scc_count++;
        }
        st.pop();
    }
 
    return scc_count;
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
    int numberOfNodes, numberOfEdges, u, v;
    cin>>numberOfNodes>>numberOfEdges;
 
    for(int i= 1; i<=numberOfNodes; i++){
        vis[i] = false;
        graph[i].clear();
        transpose_graph[i].clear();
    }
 
    for(int i= 0; i<numberOfEdges; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        transpose_graph[v].push_back(u);
    }
 
    int components= kosarajuSCC(numberOfNodes);
    if(components==1)
        cout<<"YES"<<'\n';
    else{
        cout<<"NO"<<'\n';
        for(int i=2;i<=numberOfNodes;i++)
        {
            if(ans[i]!=ans[1])
            {
                if(nv!=0)
                cout<<1<<" "<<nv<<'\n';
                else cout<<i<<" "<<"1"<<'\n'; 
                break;
            }
        }
      
    }
 
    return 0;
}
