#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 26
struct trinode{
    struct trinode* child[sz];
    int count;
    bool isEnd;
};
struct trinode* getnode(){
    struct trinode* pnode=new trinode;
    pnode->count=0;
    pnode->isEnd=false;
    for(int i=0;i<sz;i++){
        pnode->child[i]=NULL;

    }
    return pnode;
}
void insert(struct trinode* root,string s){
    struct trinode* t=root;
    for(int i=0;i<s.size();i++){
        int d=s[i]-'a'; 
        if(!t->child[d])
            t->child[d]=getnode();
        t=t->child[d];
        t->count++;

     }
   t->isEnd=true;
}
int search(struct trinode* root,string s){
    struct trinode* t=root;
    for(int i=0;i<s.size();i++){
        int d=s[i]-'a';
        if(!t->child[d])
            return 0;
        t=t->child[d];
    }
   return t->count;
}
bool isEmpty(struct trinode* root){
    for(int i=0;i<sz;i++){
        if(root->child[i])
            return false;
    }
    return true;
}
struct trinode* remove(struct trinode* root,string s,int dep=0){
    if(!root)
        return NULL;
    if(dep==s.size()){
        if(root->isEnd)
            root->isEnd=false;
        if(isEmpty(root)){
            delete(root);
            root=NULL;
        }
        return root;
    }
    int d=s[dep]-'a';
    root->child[d]=remove(root->child[d],s,dep+1);
    if(isEmpty(root) && root->isEnd==false){
        delete(root);
        root=NULL;
    }
    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    struct trinode* root=getnode();
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(root,s);
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        int ans=search(root,s);
        cout<<ans<<'\n';
    }
    return 0;
}
/*
Trie

Ada and indexing(2A spoj)
Shortest names(2B uva)
Diccionario portunol(2C uva)
Good Substring(4A cf)
Vasiliy's multiset(4D cf)
Hyper prefix Sets(5J uva)
word combinations(cses)
*/
