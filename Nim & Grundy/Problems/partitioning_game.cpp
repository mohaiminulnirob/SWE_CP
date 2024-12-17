#include<bits/stdc++.h>
using namespace std;

int grundy[10005];
bool vis[10005];
int calculateGrundy(int n)
{
    memset(vis,false,sizeof(vis));
    if(n<3) return 0;

    if(grundy[n]!=-1) return grundy[n];


    int mid=n/2;
    if(n%2==0) mid--;

    for(int i=1;i<=mid;i++)
    {
        vis[grundy[i]^grundy[n-i]]=true;
    }

    for(int j=0;j<10001;j++)
        if(vis[j]==false)
            return grundy[n]=j;

}

int main()
{
    ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
     memset(grundy,-1,sizeof(grundy));
   for(int i=1;i<=10000;i++)
    grundy[i]=calculateGrundy(i);
   int t;
   cin>>t;
   int cs=0;
   while(t--)
   {
       cs++;
       int n;
       cin>>n;
       int xs=0;
       for(int i=0;i<n;i++)
       {
           int x;
           cin>>x;
           xs^=grundy[x];
       }

       if(xs==0)
        cout<<"Case "<<cs<<": Bob"<<"\n";
       else cout<<"Case "<<cs<<": Alice"<<"\n";
   }

    return 0;
}
