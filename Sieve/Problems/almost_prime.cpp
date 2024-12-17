#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
int ans,N;

void sieve(){
  vector<int>pd_count(N+1,0);
  for(int i=2;i<=N;i++){
    if(pd_count[i]==0){
      for(int j=i;j<=N;j+=i) {
        pd_count[j]++;;
      }
    }
  }
  for(int i=2;i<=N;i++){
    if(pd_count[i]==2){
      ans++;
    }
  }
}

int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

  int t=1;
  //cin>>t;
  while(t--)
  {
  	cin>>N;
  	sieve();
  	cout<<ans<<'\n';
   
  }
  return 0;
}