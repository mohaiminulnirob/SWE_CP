#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
const int N=2e5+9;
vector<int>a[N];
int vis[N];
int n,m,ans;
int cat[N];
void dfs(int start,int c)
{
    vis[start]=1;
    if(c>m)
        return;
    for(auto child:a[start])
    {
        if(vis[child]!=1 && c<=m)
        {
            if(cat[child])
                dfs(child,c+1);
            else dfs(child,0);
        }
        
    }
    if(a[start].size()==1 && start!=1)
        ans++;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif 
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cat[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,cat[1]);
    cout<<ans<<'\n';
   
    return 0;

}
