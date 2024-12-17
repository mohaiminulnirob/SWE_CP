#include<bits/stdc++.h>
using namespace std;
 
#define mx 200009
int arr[mx];
int t[mx * 4];
void init(int node, int b, int e)
{
    if (b == e) {
        t[node] = arr[b];
    }
    else{
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    t[node] = max(t[Left] , t[Right]);
    }
}
int query(int node, int b, int e,int x)
{
    if (t[node]<x)
        return INT_MAX;
    if (t[node]>=x && b==e)
        return b;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    if(t[Left]>=x)
        return query(Left, b, mid, x);
    else
        return query(Right, mid + 1, e,x);
}
void update(int node, int b, int e, int i,int x)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        t[node] = t[node]-x;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i,x);
    update(Right, mid + 1, e, i,x);
    t[node] = max(t[Left], t[Right]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
 
    int m,n;
    cin >> m>>n;
    for(int i=1;i<=m;i++)
        cin>>arr[i];
    init(1, 1, m); 
    int q[n];
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
        int x=q[i];
        int ans=query(1,1,m,x);
        if(ans!=INT_MAX)
        {
            update(1,1,m,ans,x);
            cout<<ans<<" ";
        }
        else cout<<"0"<<" ";
    }
    return 0;
}