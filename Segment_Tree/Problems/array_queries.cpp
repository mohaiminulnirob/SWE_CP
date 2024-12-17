#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
const int N=2e5+9;
int arr[N];
int tree[N*4];
void init(int node,int b,int e)
{
    if(b==e) {
        tree[node]=arr[b];
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
        memset(arr,0,sizeof(arr));
        cs++;
        int n,c;
        cin>>n>>c;
        for(int i=1;i<=n;i++){
        	cin>>arr[i];
        }
        init(1,1,n);
        cout<<"Case "<<cs<<":"<<'\n';
        while(c--){
            int x,y;
            cin>>x>>y;
            int ans=query(1,1,n,x,y);
            cout<<ans<<'\n';
        }

    }
    return 0;
}
