#include<bits/stdc++.h>
using namespace std;
int vis[55][55];
int level[55][55];
string graph[55];
pair<int,int>current; 
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int r,c;

int bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    level[x][y]=1;
    int lev=1;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
         for(int k=0;k<8;k++){
            int nx=current.first+dx[k];
            int ny=current.second+dy[k];

            if(nx>=0 && nx<r && ny>=0 && ny<c && !vis[nx][ny] && graph[nx][ny]==graph[current.first][current.second]+1){
                q.push({nx,ny});
                vis[nx][ny]=1;
                level[nx][ny]=level[current.first][current.second]+1;
                lev=level[current.first][current.second]+1;
            }
         }
    }
    return lev;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int cs=0;
    while(1){  
        cs++;     
        cin>>r>>c;
        if(r==0 && c==0)
            break;       
        vector<pair<int,int>>v;
        for(int i=0;i<r;i++){
            
            cin>>graph[i];
             for (int j=0;j<c;j++){
                if(graph[i][j]=='A')
                    v.push_back({i,j});
            }                     
        }              
        int ans=0;
        for(auto u:v){
            memset(vis,0,sizeof(vis));
            memset(level,0,sizeof(level));
            int ans1=0;
            ans1=bfs(u.first,u.second);
            ans=max(ans,ans1);
        }
        cout<<"Case "<<cs<<": "<<ans<<endl;    
        }
        return 0;
}

