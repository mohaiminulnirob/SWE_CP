#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000009
int tree[N*4];


int query(int node,int b,int e,int i,int j)
{
    if (i>e || j<b)
        return 0;
    if (b==i && e==j)
        return tree[node];
    int Left=node*2;
    int Right=node*2 + 1;
    int mid=(b+e)/2;
    int x=query(Left,b,mid,i,j);
    int y=query(Right,mid+1,e,i,j);
    if(x==0 and y==0)
        return tree[node];
    else return x+y;
}

void update(int node,int b,int e,int i,int j,int value)
{
    if (i>e || j<b )
        return;
    if(tree[node]!=0)
    {
        return;
    }
    if (b>=i && e<=j) {
        tree[node]=value;
        return;
    }
    int Left=node*2;
    int Right=node * 2 + 1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,value);
    update(Right,mid+1,e,i,j,value);
}

int32_t main()
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
        int l,r,x;
        cin>>l>>r>>x;
        update(1,1,n,l,x-1,x);
        update(1,1,n,x+1,r,x);
    }
    for(int i=1;i<=n;i++)
        cout<<query(1,1,n,i,i)<<" ";
    cout<<'\n';
    
    return 0;
}
