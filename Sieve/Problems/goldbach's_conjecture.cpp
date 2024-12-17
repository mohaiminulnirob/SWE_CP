#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=1e7;
vector<int>primes;
bool is_prime[N];

void sieve(){
  for(int i=2;i<N;i++){
    is_prime[i]=true;
  }
  for(int i=2;i*i<N;i++){
    if(is_prime[i]){
      for(int j=i*i;j<N;j+=i) {
        is_prime[j]=false;
      }
    }
  }
  for(int i=2;i<N;i++){
    if(is_prime[i]){
      primes.pb(i);
    }
  }
}

int32_t main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 

  int t=1,cs=0;
  cin>>t;
  sieve();
  while(t--)
  { 
    cs++;  
    int n,ans=0;
    cin>>n;
    for(int u:primes){
      int x=n-u;
      if(x<u)
        break;
      if(is_prime[x]==true)
        ans++;
    }
    cout<<"Case "<<cs<<": "<<ans<<'\n';
  }
  return 0;
}