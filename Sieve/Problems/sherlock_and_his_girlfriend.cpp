#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
bool not_prime[N+1];
void sieve(){
  for(int i=2;i*i<=N;i++){
    if(!not_prime[i]){
      for(int j=i*i;j<=N;j+=i){
        not_prime[j]=true;
      }
    }
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
  //cin>>t;
  while(t--)
  {
        sieve();
        int n;
        cin>>n;
        if(n>2)
        cout<<"2"<<'\n';
        else cout<<"1"<<'\n';
        for(int i=1;i<=n;i++){
          if(not_prime[i+1])
            cout<<"2 ";
          else cout<<"1 ";
        }
        cout<<'\n';
  }
  return 0;
}