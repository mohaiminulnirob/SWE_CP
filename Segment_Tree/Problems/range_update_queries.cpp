#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200009
int arr[N];
int tree[N*4];
int lazy[N*4];

void push(int node, int b, int e) {
    if(lazy[node]==0) {
        return;
    }
    tree[node]=tree[node]+lazy[node]*((e-b)+1);//changeable
    if(b!=e) {
        int Left=node*2;
        int Right=node*2+1;
        lazy[Left]=lazy[Left]+lazy[node];
        lazy[Right]=lazy[Right]+lazy[node];
    }
    lazy[node]=0;
}

void init(int node, int b, int e)
{
    lazy[node]=0;
    if (b==e) {
        tree[node]=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];//changable
}

int query(int node,int b,int e,int i,int j)
{
    push(node,b,e);
    if (i>e || j<b)
        return 0;
    if (b>=i && e<=j)
        return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;//changable
}

void update(int node,int b,int e,int i,int j,int value)
{
    push(node,b,e);
    if (i>e || j<b)
        return;
    if (b>=i && e<=j) {
       lazy[node]=value;
       push(node,b,e);
       return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,value);
    update(Right,mid+1,e,i,j,value);
    tree[node]=tree[Left]+tree[Right];//changable
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    init(1,1,n);
    while(q--){
        int k;
        cin>>k;
        if(k==2){
            int x;
            cin>>x;
            int ans=query(1,1,n,x,x);
            cout<<ans<<'\n';
        }
        else {
            int x,y,z;
            cin>>x>>y>>z;
            update(1,1,n,x,y,z);
        }
    }
    return 0;
}
