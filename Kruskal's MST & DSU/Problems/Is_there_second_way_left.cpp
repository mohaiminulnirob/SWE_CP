#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=110;
int parent[N];
int sz[N];
int rk[N];
vector<pair<int,pair<int,int>>> edges;
vector<pair<int,pair<int,int>>> mst_edges;
int n, m;
ll cost, cost1;
bool impossible;
void make(int v){
    parent[v] = v;
    sz[v]=1;
    rk[v]=0;
}
int find(int v){
    if(v==parent[v])
        return v;
    return parent[v]=find(parent[v]);
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(rk[b]>rk[a])
            swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
        if(rk[b]==rk[a])
            rk[a]++;
    }
}
ll kruskals(bool secondMST){
    for(int i=1;i<=n;i++){
        make(i);
    }   
    sort(edges.begin(), edges.end());
    ll total_cost=0;
    int count=0;   
    for(auto e:edges){
        int w=e.first;
        int u=e.second.first;
        int v=e.second.second;       
        if(find(u)==find(v))
          continue;       
        Union(u,v);
        total_cost+=w;
        count++;
        
        if(!secondMST){
            mst_edges.push_back(e);
        }       
        if(count==n-1)
            break;
    }   
    if(count!=n-1)
        return LLONG_MAX;   
    return total_cost;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int t=1,cs=0;
    cin>>t;
    while(t--){
        cs++;
        edges.clear();
        mst_edges.clear();
        cin>>n>>m;
        
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({w,{u,v}});
        }
        
        cost=kruskals(false);
        cout<<"Case #"<<cs<<" : ";
        if(cost==LLONG_MAX) {
            cout<<"No way"<<'\n';
            continue;
        }
        
        cost1=LLONG_MAX;
        for(auto edge:mst_edges) {
            edges.erase(find(edges.begin(),edges.end(),edge));
            cost1=min(cost1, kruskals(true));
            edges.push_back(edge);
        }        
        if(cost1==LLONG_MAX)
            cout<<"No second way"<<'\n';
        else
            cout<<cost1<<'\n';
    }
    return 0;
}
