#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000007
int arr[N],tree[4*N];

struct lazyNode{
    int initial = 0;
    int freq= 0;
};

lazyNode lazy[4*N];

void init(int node,int b,int e){
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

void push(int node,int b,int e){
    if( lazy[node].freq ){
        tree[node]+=  (e-b+1)*(2*lazy[node].initial+(e-b)*lazy[node].freq)/2;//Sn = n/2 [2a + (n - 1) d]

        if( b!=e ){

            int mid = (b+e)/2;
            int Left=node*2;
            int Right=node*2+1;

            lazy[Left].initial+=lazy[node].initial;
            lazy[Right].initial+=lazy[node].initial+(mid-b+1)*lazy[node].freq;//from left every value
            //increases by d till mid+1

            lazy[Left].freq+=lazy[node].freq;
            lazy[Right].freq+=lazy[node].freq;
        }
        lazy[node]={0,0};
    }
}

void update(int node,int b,int e,int i,int j){
    push(node,b,e);

    if(b>j || e<i) 
        return;

    if(b>=i && e<=j){
        lazy[node].initial+=b-i+1;
        lazy[node].freq++;
        push(node,b,e);
        return;
    }

    int mid =(b+e)/2;
    int Left=node*2;
    int Right=node*2+1;

    update(Left,b,mid,i,j);
    update(Right,mid+1,e,i,j);

    tree[node]=tree[Left]+tree[Right] ;
}

int query(int node,int b, int e,int i,int j){
    push(node,b,e);

    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

int32_t main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>arr[i];

    init(1,1,n);

    while(q--){
        int tp;
        cin>>tp;
        if( tp == 1 ){
            int a,b;
            cin>>a>>b;
            update(1,1,n,a,b);
        } 
        else{
            int a,b;
            cin>>a>>b;
            int sum=query(1,1,n,a,b);
            cout<<sum<<'\n';
        }
    }
    return 0;
}

