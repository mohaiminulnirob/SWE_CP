#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=105;
string graph[N];
int vis[N][N];
pair<int,int>current;
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int r,c;

void bfs(int x,int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
         for(int k=0;k<8;k++){
            int nx=current.first+dx[k];
            int ny=current.second+dy[k];

            if(nx>=0 && nx<r && ny>=0 && ny<c && !vis[nx][ny] ){
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
         }
    }
}

int32_t main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

  int t=1;
  //cin>>t;
  while(t)
  {
     cin>>r>>c;
     if(r==0 && c==0)
      break;
     memset(vis,0,sizeof(vis));
     vector<pair<int,int>>v;
     for(int i=0;i<r;i++){            
          cin>>graph[i];
          for (int j=0;j<c;j++){
            if(graph[i][j]=='@')
             v.pb({i,j});
           else vis[i][j]=1;
         }
      }
      int ans=0;
      for(auto u:v){
        if(!vis[u.first][u.second]){
          ans++;
          bfs(u.first,u.second);
        }
      }
      cout<<ans<<'\n';

  }
  return 0;
}