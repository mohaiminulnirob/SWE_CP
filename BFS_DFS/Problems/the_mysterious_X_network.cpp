#include<bits/stdc++.h>
using namespace std;
map<int ,vector<int>>adjlist;
int vis[100005]={0};
int level[100005]={0};
int bfs(int start,int target)
{
    int l;
    int current;
    memset(vis,0,sizeof(vis));
    memset(level,-1,sizeof(level));
    queue<int>q;
    q.push(start);
    vis[start]=1;
    level[start]=0;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        for(auto child:adjlist[current])
        {
            if(vis[child]!=1)
            {
            q.push(child);
            vis[child]=1;
            level[child]=level[current]+1;
            }
        }
    }
    return level[target]-1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        adjlist.clear();
        for(int i=0;i<n;i++)
        {
            int c;
            cin>>c;
            int num;
            cin>>num;
            for(int j=0;j<num;j++)
            {
                int x;
                cin>>x;
                adjlist[c].push_back(x);
            }
        }
        int a,b;
        cin>>a>>b;
        int ans=bfs(a,b);
        cout<<a<<" "<<b<<" "<<ans<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}
