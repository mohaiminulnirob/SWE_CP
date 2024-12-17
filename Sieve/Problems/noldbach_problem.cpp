#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1500;
bool is_prime[N+1];
vector<int>primes(N);

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
  int k=0;
  for(int i=2;i<N;i++){
    if(is_prime[i]){
      primes[k]=i;
      k++;
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
    int n,k;
    cin>>n>>k;
    sieve();
    int c=0;
    for(int i=1;primes[i]<n;i++){
      if(is_prime[primes[i]+primes[i-1]+1] && primes[i]+primes[i-1]+1<=n)
        c++;
      //cout<<primes[i]<<'\n';

    }
    if(c>=k)
      cout<<"YES";
    else cout<<"NO"<<'\n';
        
  }
}