#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,vector<pair<int,int>>>adjlist;
int dist[10005];
bool sptSet[10005];
int V,E,src,des;

int minDistance()
{
    int min=INT_MAX,min_index;

    for(int v=1;v<=V;v++){
        if(sptSet[v]==false && dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void dijkstra()
{
    for(int i=1;i<=V;i++){
        dist[i]=INT_MAX; 
        sptSet[i]=false;
    }

    dist[src]=0;
    for(int count=1;count<V;count++){
        int u=minDistance();
        sptSet[u]=true;

        for(auto v:adjlist[u]){
            if(!sptSet[v.first] && dist[u]+v.second<dist[v.first])
                dist[v.first]=dist[u]+v.second;
        }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
    int t;
    cin>>t;
    while(t--)
    {
        cin>>V>>E;
        adjlist.clear();
        for(int i=0;i<E;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            adjlist[x].push_back({y,z});
        }
        cin>>src>>des;
        dijkstra();
        int ans=dist[des];
        if(dist[des]==INT_MAX)
            cout<<"NO"<<'\n';
        else 
            cout<<ans<<'\n';
    }
    return 0;
}