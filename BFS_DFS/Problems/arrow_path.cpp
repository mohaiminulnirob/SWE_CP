#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+9;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool vis[2][N];
int n;
string s[2];
void dfs(int x,int y){
	vis[x][y]=1;
	if((x+y)%2==0){
		for(int i=0;i<4;i++){
			int a=x+dx[i];
			int b=y+dy[i];
			if(a<2 && b<n && a>=0 && b>=0 && !vis[a][b])
				dfs(a,b);
		}
	}
	else {
		int a,b;
		if(s[x][y]=='>'){
			 a=x;
			 b=y+1;
		}
		else if(s[x][y]=='<'){
			 a=x;
			 b=y-1;
		}
		if(a<2 && b<n && a>=0 && b>=0 && !vis[a][b])
				dfs(a,b);
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
	while(t--)
	{
		memset(vis,0,sizeof(vis));
        cin>>n;
        cin>>s[0]>>s[1];
        dfs(0,0);
        if(vis[1][n-1])
        	cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
	}
	return 0;
}