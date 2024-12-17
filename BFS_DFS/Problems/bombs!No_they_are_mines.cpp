#include<bits/stdc++.h>
using namespace std;
int vis[1005][1005];
int level[1005][1005];
pair<int,int>current;
int dx[]={0,0,-1,+1};
int dy[]={+1,-1,0,0};
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
         for(int k=0;k<4;k++){
            int nx=current.first+dx[k];
            int ny=current.second+dy[k];

            if(nx>=0 && nx<r && ny>=0 && ny<c && !vis[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny]=1;
                level[nx][ny]=level[current.first][current.second]+1;
            }
         }
    }
}

int main()
{
    while(1)
    {
        cin>>r>>c;
        if(r==0 && c==0)
            break;
        int n;
        cin>>n;
        memset(vis,0,sizeof(vis));
        memset(level,0,sizeof(level));
        for(int i=0;i<n;i++)
        {
            int row,m,col;
            cin>>row>>m;
            for(int j=0;j<m;j++)
            {
                cin>>col;
                vis[row][col]=1;
            }
        }
        int startrow,startcol,endrow,endcol;
        cin>>startrow>>startcol>>endrow>>endcol;
        bfs(startrow,startcol);
        int ans=level[endrow][endcol];
        cout<<ans<<endl;
    }
}
