#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 200009
int arr[mx];
int tree[mx * 4];
int lazy[mx*4];
int amount;

void push(int node, int b, int e) {
    if (lazy[node] == 0) {
        return;
    }
    tree[node] = tree[node] + lazy[node] * ((e- b) + 1);
    if (b != e) {
        int Left = node * 2;
        int Right = node * 2 + 1;
        lazy[Left] = lazy[Left] + lazy[node];
        lazy[Right] = lazy[Right] + lazy[node];
    }
    lazy[node] = 0;
}

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    push(node, b, e);
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

void update(int node, int b, int e, int i,int qt, int newvalue)
{
    push(node, b, e);
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        if(qt==1)
        {
            amount=tree[node];
            tree[node] = newvalue;
        }
        else tree[node]+=newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i,qt, newvalue);
    update(Right, mid + 1, e, i,qt, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
    int t;
    cin>>t;
    int cs=0;
    while(t--)
    {
        cs++;
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        init(1,1,n);
        cout<<"Case "<<cs<<":"<<'\n';
        while(q--)
        {
            int a;
            cin>>a;
            if(a==1)
            {
                int b;
                cin>>b;
                update(1,1,n,b+1,1,0);
                cout<<amount<<'\n';
            }
            else if(a==2)
            {
                int b,c;
                cin>>b>>c;
                update(1,1,n,b+1,2,c);
            }
            else{
                int b,c;
                cin>>b>>c;
                amount=query(1,1,n,b+1,c+1);
                cout<<amount<<'\n';
            }

        }
    }
    
    return 0;
}
