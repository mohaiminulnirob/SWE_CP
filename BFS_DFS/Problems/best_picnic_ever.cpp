#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>adjlist;
int vis[1005];
int trav[1005];
int a[105];
int k,n,m,i,ans,x,y,current,t,j,c;
int main()
{
    cin>>t;
    for(c=1;c<=t;c++)
    {
        cin>>k>>n>>m;
        for(i=0;i<k;i++)
            cin>>a[i];
        adjlist.clear();
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            adjlist[x].push_back(y);
        }
        for(i=1;i<=n;i++)
            vis[i]=0;
        for(i=0;i<k;i++)
        {
            for(j=1;j<=n;j++)
               trav[j]=0;
            queue<int>q;
            q.push(a[i]);
            vis[a[i]]++;
            trav[a[i]]++;
            while(!q.empty())
            {
                current=q.front();
                q.pop();
                for(auto child:adjlist[current])
                {
                    if(trav[child]==0)
                    {
                        q.push(child);
                        vis[child]++;
                        trav[child]++;
                     }
                 }
            }


        }
        ans=0;
            for(i=1;i<=n;i++)
            {
                if(vis[i]>=k)
                    ans++;
            }
            cout<<"Case "<<c<<": "<<ans<<endl;

    }
    return 0;
}
