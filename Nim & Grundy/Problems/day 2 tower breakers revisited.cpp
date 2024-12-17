#include<bits/stdc++.h>
using namespace std;
int grundy[1000001];
#define int long long
vector<int>divisors[1000001];

void sieve()
{
    for(int i=1;i<1000001;i++)
    {
        for(int j=i;j<1000001;j=j+i)
        {
            if(i!=j)
            divisors[j].push_back(i);
        }
    }
}

int calMex(set<int>set)
{
    int mex=0;
    while(set.find(mex) != set.end())
        mex++;
    return mex;
}

int sg(int x)
{
    if(x==1 || x==0)
    {
        return 0;
    }
    if(grundy[x]!=-1)
    {
        return grundy[x];
    }
    set<int>s;
    for(int i=0;i<divisors[x].size();i++)
    {
        int y=divisors[x][i];
        s.insert(sg(y));
    }
    grundy[x]=calMex(s);
    return grundy[x];
}


int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    sieve();
    memset(grundy,-1,sizeof(grundy));
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int xs=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            xs=xs^sg(x);
        }
        if(xs==0)
            cout<<"2"<<'\n';
        else cout<<"1"<<'\n';
    }
    return 0;
}

