#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=2e5+9;
int ans;
#define sz 2
struct trinode{
    struct trinode* child[sz];
    int count;
};
struct trinode* getnode(){
    struct trinode* pnode=new trinode;
    pnode->count=0;
    for(int i=0;i<sz;i++){
        pnode->child[i]=NULL;

    }
    return pnode;
}
void insert(struct trinode* root,string s){
    struct trinode* t=root;
    for(int i=0;i<s.size();i++){
        int d=s[i]-'0';
        if(!t->child[d])
            t->child[d]=getnode();
        t=t->child[d];
        t->count++;
        ans=max(ans,(i+1)*t->count);
     }
}
int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        struct trinode* root=getnode();
        ans=0;
        for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(root,s);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
