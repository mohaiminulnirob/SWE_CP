#include<bits/stdc++.h>
using namespace std;
vector<int>a[100005];
int vis[100005];
int level[100005];
int imp=0;
void bfs(int start)
{
    int current;
    queue<int>q;
    q.push(start);
    level[start]=1;
    vis[start]=1;
    while(!q.empty() && imp==0)
    {
        current=q.front();
        q.pop();
        for(auto child:a[current])
        {
            if(vis[child]!=1)
            {
            q.push(child);
            vis[child]=1;
            level[child]=(level[current]+1)%2;
            }
            else if(vis[child] && level[child]==level[current])
            {
                imp=1;
                break;
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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])
            bfs(i);
    }
    if(imp){
        cout<<"IMPOSSIBLE"<<'\n';
    }
    else {
        for(int i=1;i<=n;i++){
            if(level[i]==0)
                cout<<"2 ";
            else cout<<"1 ";
        }
        cout<<'\n';
    }
    return 0;
 
}
