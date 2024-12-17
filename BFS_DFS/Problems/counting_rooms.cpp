#include<bits/stdc++.h>
using namespace std;
#define int long long
string graph[1005];
int vis[1005][1005];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int open=0;
int n,m;
void bfs(int x,int y){
    pair<int,int>current;
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty()){
        current=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx=current.first+dx[i];
            int yy=current.second+dy[i];
        if(xx>=n || xx<0 || yy>=m && yy<0){
            continue;
        }
        
        if(graph[xx][yy]=='.' && vis[xx][yy]==0)
        {
            //cout<<xx<<" ! "<<yy<<'\n';
            vis[xx][yy]=1;
            q.push({xx,yy});
        }
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
 
    int t=1;
    //cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        //int n,m;
        cin>>n>>m;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            cin>>graph[i];
        
        for(int j=0;j<m;j++){
            if(graph[i][j]=='.'){
                v.push_back({i,j});
            }
        }
       }
       int count=0;
       //cout<<v.size()<<'\n';
       for(auto u:v){
        if(!vis[u.first][u.second]){
            bfs(u.first,u.second);
            //if(!open)
            count++;
            open=0;
        }
        //cout<<count<<'\n';
       }
       cout<<count<<'\n'; 
    }
    return 0;
}
