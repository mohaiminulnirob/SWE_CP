#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=1e8;
vector<int>primes;
bool is_prime[N]; 

void sieve() {
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
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif 

  sieve();
  int n=primes.size();
  for(int i=0;i<n;i+=100)
    cout<<primes[i]<<'\n';
  return 0;
}