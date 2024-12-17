#include<bits/stdc++.h>
using namespace std;

const int max_node = 100009;
int ans[max_node];
int scc_count=0;
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

void dfs_print(int n){
    if(vis[n] == true) return;

    ans[n]=scc_count+1;

    int len= transpose_graph[n].size();
    vis[n]= true;

    for(int i= 0; i<len; i++){
        dfs_print(transpose_graph[n][i]);
    }
}

int kosarajuSCC(int numberOfNodes){
    for(int i=1; i<=numberOfNodes; i++){
        if(vis[i] == false){
            dfs(i);
        }
    }

    for(int i=1; i<=numberOfNodes; i++){
        vis[i]=false;
    }

    while(!st.empty()){
        if(vis[st.top()] == false){
            dfs_print(st.top());
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
    cout<<components<<'\n';
    for(int i=1;i<=numberOfNodes;i++)
        cout<<ans[i]<<" ";
    cout<<'\n';

    return 0;
}
/*
SCC 

Flight Routes Check(Kosaraju)(2k-cses)
Planets and Kingdoms(Kosaraju)(2L-cses)
*/
