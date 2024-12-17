#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[32];
map<string,vector<pair<string,double>>>adjlist;
map<string,double>val;
map<string,int>vis;

void bfs(string s){
    string current;
    queue<string>q;
    q.push(s);
    val[s]=1.0000;
    while(!q.empty() && !vis[s]){
        current=q.front();
        q.pop();
        for(auto u:adjlist[current]){
            if(u.first==s){
                if(val[current]*u.second>val[s]){
                    val[s]=val[current]*u.second;
                    vis[s]=1;
                    break;
                }
                else continue;
            }
            if(val[u.first]<val[current]*u.second){
                q.push(u.first);
                val[u.first]=val[current]*u.second;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int cs=0;
    while(1)
    {
        cs++;
        int n;
        cin>>n;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            cin>>s[i];
        int m;
        cin>>m;
        adjlist.clear();
        for(int i=0;i<m;i++){
            double x;
            string a,b;
            cin>>a>>x>>b;
            adjlist[a].push_back({b,x});
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            val.clear();
            vis.clear();
            bfs(s[i]);
            if(val[s[i]]>1.0000){
                ans=1;
                break;
            }
        }
        if(ans)
            cout<<"Case "<<cs<<": Yes"<<'\n';
        else cout<<"Case "<<cs<<": No"<<'\n';
    }
    return 0; 
}
/*
BFS

Oil deposits(5B cf)
Graph Connectivity(5C uva)
Kefa and park(dfs)(5D cf)
Counting rooms(cses)
Labyrinth(cses)
Building roads(cses)
Building teams(cses)
Arrow path(cf)
ABCpath(lab final1 C spoj)
All roads leads where(1M uva)
Bombs! no they are mines(1N uva)
The mysterious x-network(1O uva)
Shipping routes(1P uva)
Best picnic ever(1U lightoj)
Escape(1V lightoj)
Farthest node in a tree(5E,1W lightoj)
Farthest node in a tree II(1X lightoj)
Ada & cycle(3A spoj)
Spiky mazes(3B spoj)
Spiders(3D cf)
Arbitrage(3F spoj)
Adrita and bike ride(3H spoj)

*/