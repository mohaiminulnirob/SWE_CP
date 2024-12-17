#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll divisors_sum(int x){
  ll s=0;
  for(int i=1;i*i<=x;i++){
    if(x%i==0){
      if(i*i<x)
        s+=i+x/i;
      else s+=i;
    }
  }
  s-=x;
  return s;
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
  while(t--)
  {
    int x;
    cin>>x;
    cout<<divisors_sum(x)<<'\n';
  }
  return 0;
}