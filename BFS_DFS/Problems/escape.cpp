#include<bits/stdc++.h>
using namespace std;
#define ll long long
//int level[105];
int vis[105][2];
int level;
map<int,vector<int>>adjlist;
void bfs(int src){
    //vis[src][1]=1;
    int current;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        current=q.front().first;
        level=q.front().second;
        q.pop();
        level=(level+1)%2;
        //cout<<level<<'\n';
        for(auto u:adjlist[current]){
            if(!vis[u][level]){
                q.push({u,level});
                vis[u][level]=1;
                // if(level==1){
                //    cout<<u<<" "<<current<<"!"<<'\n';
                // }
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int t;
    cin>>t;
    int cs=0;
    while(t--)
    {
        cs++;
        adjlist.clear();
        memset(vis,0,sizeof(vis));
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adjlist[x].push_back(y);
            adjlist[y].push_back(x);
        }
        int ans=0;
        bfs(1);
        for(int i=1;i<=n;i++){
            if(vis[i][1])
                ans++;

        }
        cout<<"Case "<<cs<<": "<<ans<<'\n';
    }
}