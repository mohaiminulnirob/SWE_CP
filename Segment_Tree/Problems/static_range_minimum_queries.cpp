#include<bits/stdc++.h>
using namespace std;
 
#define N 200009
#define int long long
int a[N];
int tree[N*4];
void init(int node,int b,int e)
{
    if(b==e) {
        tree[node]=a[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid= (b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=min(tree[Left],tree[Right]);
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return INT_MAX;
    if(b>=i && e<=j)
        return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return min(p1,p2);
}
void update(int node,int b,int e,int i,int value)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i) {
 
       tree[node]=value;
       return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,value);
    update(Right,mid+1,e,i,value);
    tree[node]=tree[Left]+tree[Right];//changable
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
    int cs=0;
    while(t--){
    cs++;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init(1,1,n);
    cout<<"Case "<<cs<<":"<<'\n';
    while(q--){
        int x,y;
        cin>>x>>y;    
        int ans=query(1,1,n,x,y);
        cout<<ans<<'\n';
    }
    }
    
    return 0;
}