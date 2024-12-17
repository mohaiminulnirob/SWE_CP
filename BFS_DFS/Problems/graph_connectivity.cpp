#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=30;
map<int,vector<int>>a;
int vis[N];

void bfs(int start)
{
    queue<int>q;
    q.push(start);
    vis[start]=1;
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        for(auto child:a[current])
        {
          if(vis[child]!=1 ){
            q.push(child);
            vis[child]=1;
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
  cin>>t;
  while(t--)
  {
    memset(vis,0,sizeof(vis));
    a.clear();
    char C;
    cin>>C;
    cin.ignore();
    int nodes=C-'A'+1;
    string s;
    while(getline(cin,s) && s!=""){
      a[s[0]-'A'+1].pb(s[1]-'A'+1);
      a[s[1]-'A'+1].pb(s[0]-'A'+1);
    }
    int ans=0;
    for(int i=1;i<=nodes;i++){
      if(!vis[i]){
        bfs(i);
        ans++;
      }
    }
   cout<<ans<<'\n';
   if(t)
     cout<<'\n';
  }
  return 0;
}