#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
int grundy[10005];
int a[105];
int k;

int calculateMex(set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}


int calculateGrundy(int X)
{
    if(X<a[0])
    {
        return 0;
    }
    if(grundy[X]!=-1)
    {
        return grundy[X];
    }

    set<int>s;
    for(int i=0;i<k;i++)
    {
        if(X>=a[i])
        s.insert(calculateGrundy(X-a[i]));
    }
    grundy[X] = calculateMex (s);
    return grundy[X];
}


int main()
{
    cin>>k;
    for(int i=0;i<k;i++)
        cin>>a[i];
    sort(a,a+k);
    int t;
    cin>>t;
    memset(grundy,-1,sizeof(grundy));
    while(t--)
    {
        int l;
        cin>>l;
        int xs=0;
        for(int i=0;i<l;i++)
        {
            int x;
            cin>>x;
            xs=xs^calculateGrundy(x);
        }
        if(xs==0)
            cout<<"L";
        else cout<<"W";
    }
}
