#include<bits/stdc++.h>
using namespace std;
#define N 200009
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
    tree[node]=__gcd(tree[Left],tree[Right]);
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return __gcd(p1,p2);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,vector<int>>m;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            m[arr[i]].push_back(i);
        }
        init(1,1,n);
        int q;
        cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;
            int x=query(1,1,n,l,r);
            int y=upper_bound(m[x].begin(),m[x].end(),r)-lower_bound(m[x].begin(),m[x].end(),l);
            int ans=r-l+1-y;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
