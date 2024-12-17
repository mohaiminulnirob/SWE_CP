#include<bits/stdc++.h>
using namespace std;
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
        int m,n;
        cin>>m>>n;
        map<string,vector<string>>adj;
        for(int i=0;i<m;i++)
        {
            string x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            string a,b;
            cin>>a>>b;
            map<string,string>orig;
            map<string,int>vis;
            queue<string>q;
            q.push(a);
            vis[a]=1;
            string current;
            int br=0;
        while(!q.empty() && !vis[b])
        {
            current=q.front();
            q.pop();
            for(auto child:adj[current])
            {
                if(vis[child]!=1)
                {
                    q.push(child);
                    vis[child]=1;
                    orig[child]=current;
                }
                if(child==b)
                {
                    break;
                }
             }
        }
        string ans;
        ans.push_back(b[0]);
        current=b;
         while(current!=a)
        {
           ans.push_back(orig[current][0]);
          current=orig[current];
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;

       }
       if(t)
        cout<<endl;
    }
    return 0;
}
