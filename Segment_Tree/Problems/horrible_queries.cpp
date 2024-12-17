#include<bits/stdc++.h>
using namespace std;

#define int long long
#define N 200009
int arr[N];
int tree[N*4];
int lazy[N*4];
void push(int node,int b,int e) {
    if(lazy[node]==0) {
        return;
    }
    tree[node]=tree[node]+lazy[node]*((e-b)+1);
    if(b!=e) {
        int Left=node*2;
        int Right=node*2+1;
        lazy[Left]=lazy[Left]+lazy[node];
        lazy[Right]=lazy[Right]+lazy[node];
    }
    lazy[node]=0;
}

void init(int node,int b,int e)
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
    tree[node]=tree[Left]+tree[Right];
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
    return p1+p2;
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
    tree[node]=tree[Left]+tree[Right];
}

int32_t main()
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
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        memset(arr,0,sizeof(arr));
        int n,c;
        cin>>n>>c;
        init(1,1,n);
        while(c--){
            int x;
            cin>>x;
            if(x==1){
                int p,q;
                cin>>p>>q;
                int ans=query(1,1,n,p,q);
                cout<<ans<<'\n';
            }
            else{
                int p,q,r;
                cin>>p>>q>>r;
                update(1,1,n,p,q,r);
            }
        }
    }
    
    return 0;
}
