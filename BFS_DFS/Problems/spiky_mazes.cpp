#include<bits/stdc++.h>
using namespace std;
#define int long long
int dx[]={0,0,-1,+1};
int dy[]={+1,-1,0,0};
string s[45];
int spk[45][45];
int n,m;

int bfs(int x,int y)
{
	pair<int,int>current;
    queue<pair<int,int>>q;
    q.push({x,y});
    spk[x][y]=0;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
         for(int k=0;k<4;k++){
         	int spkt;
            int nx=current.first+dx[k];
            int ny=current.second+dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m)
            	continue;
            else if(s[nx][ny]=='s')
            	spkt=spk[current.first][current.second]+2;
            else if(s[nx][ny]=='x')
            	return spk[current.first][current.second];
            else if(s[nx][ny]=='#')
            	continue;
            else spkt=spk[current.first][current.second];

            if(spkt<spk[nx][ny]){
                q.push({nx,ny});
                spk[nx][ny]=spkt;
            }
         }
    }
    return INT_MAX;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

	int o;
	cin>>n>>m>>o;
	vector<pair<int,int>>entr;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			spk[i][j]=INT_MAX;
	}
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			if(s[i][j]=='@'){
				entr.push_back({i,j});
			}
		}
	}
	int ans=0;
	for(auto u:entr)
	{
		int ttl=bfs(u.first,u.second);
	    if(ttl<=o){
	    	ans=1;
	    	break;
	    }
	}
	if(ans)
		cout<<"SUCCESS"<<'\n';
	else cout<<"IMPOSSIBLE"<<'\n';
	return 0;
}