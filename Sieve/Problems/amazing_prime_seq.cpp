#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int N=1e7+9;
const int mod=1e9+7;
int spf[N];

void sieve(){
  for(int i=2;i<N;i++){
    spf[i]=i;
  }
  for(int i=2;i*i<N;i++){
    if(spf[i] == i){
      for(int j=i*i;j<N;j+=i) {
        spf[j]=min(spf[j],i);
      }
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

  int t=1;
  cin>>t;
  sieve();
  while(t--)
  {
    int n;
    cin>>n;
    ll a[n+1];
    a[1]=0;
    for(int i=2;i<=n;i++){
      a[i]=a[i-1]+spf[i];
    }
    cout<<a[n]<<'\n';

  }
  return 0;
}