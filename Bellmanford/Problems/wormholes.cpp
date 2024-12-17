#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int graph[2000][3];
int dis[1000];
bool impossible;
void bellmanford(int src){
    dis[src]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(dis[graph[j][0]]!=INT_MAX && dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]]){
                dis[graph[j][1]]=dis[graph[j][0]]+graph[j][2];
            }
        }
    }
    for(int j=0;j<m;j++){
        if(dis[graph[j][0]]!=INT_MAX && dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]]){
            impossible=true;
            break;
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
        impossible=false;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            graph[i][0]=x;
            graph[i][1]=y;
            graph[i][2]=z;
        }
        for(int i=0;i<n;i++)
        {
           dis[i]=INT_MAX;
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX)
                bellmanford(i);
            if(impossible)
                break;

        }
        if(impossible)
            cout<<"possible"<<'\n';
        else cout<<"not possible"<<'\n';
        
    }
    return 0;
}