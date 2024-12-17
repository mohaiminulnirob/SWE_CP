#include<bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int>>>adjlist;
long long vis[30005][2];
long long t1ans[30005],t2ans[30005];

void dfs(int start)
{
    vis[start][0]=1;
        for(auto child:adjlist[start])
        {
            if(vis[child.first][0]!=1)
            {
            //vis[child.first][0]=1;
            vis[child.first][1]=vis[start][1]+child.second;
            dfs(child.first);

            }
        }
}
int main()
{
    int t,c=0;
    cin>>t;
    while(t--)
    {
        c++;
        memset(vis,0,sizeof(vis));
        adjlist.clear();
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adjlist[u].push_back(std:: make_pair(v,w));
            adjlist[v].push_back(std:: make_pair(u,w));
        }
        dfs(0);
        long long m=0;
        int node1,node2;
        for(int i=0;i<n;i++)
        {
           if(vis[i][1]>m)
           {
               node1=i;
               m=vis[i][1];
           }

        }
        memset(vis,0,sizeof (vis));
        dfs(node1);
        m=0;
        for(int i=0;i<n;i++)
        {
           t1ans[i]=vis[i][1];
           if(vis[i][1]>m)
           {
               node2=i;
               m=vis[i][1];
           }
        }
        memset(vis,0,sizeof (vis));
        dfs(node2);
        for(int i=0;i<n;i++)
        {
           t2ans[i]=vis[i][1];
        }
        cout<<"Case "<<c<<":"<<endl;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
           ans = max(t1ans[i],t2ans[i]);
           cout<<ans<<endl;
        }
    }
    return 0;
}
