#include<bits/stdc++.h>
using namespace std;
#define int long long 

struct node {
  node* child[26];
};

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    while(t--){
      string s;
      string g;
      int k;
      cin>>s>>g>>k;
      
      node* r=new node();
      int n=s.length();
      int ttl=0;
      for(int i=0;i<n;i++){
        node* t=r;
        int cnt=0;
        for(int j=i;j<n;j++){
          if(g[s[j]-'a']=='0')
            cnt++;
          if(cnt>k)
            break;
          if(t->child[s[j]-'a']==NULL){
            t->child[s[j]-'a']=new node();
            ttl++;
          }
          t=t->child[s[j]-'a'];
        }
      }
      cout<<ttl<<'\n';

    }
    return 0;
}