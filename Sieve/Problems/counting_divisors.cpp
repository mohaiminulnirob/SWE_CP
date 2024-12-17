#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int divisors[N+1];

//counting diviosrs using prime factorization
//number of divisors(upper bound) is cubic root of n(approximate)
void divisor(){
  for(int i=1;i<=N;i++)
    divisors[i]=1;
  for(int i=1;i<=N;i++){
    int n=i;
    for (int x=2;x*x<=n;x++){
      int c=0;
       while (n%x == 0) {
         c++;
         n/=x;
        }
        divisors[i]*=(c+1);
    }
    if(n>1)divisors[i]*=2;
  }
}
// void divisor(){
//   for(int i=1;i<=N;i++){
//     for(int j=i;j<=N;j+=i){
//       divisors[j]++;

//     }
//   }
//}
// void divisor(){
//   for(int i=1;i<=N;i++){
//     int j;
//      for(j=1;j*j<=i;j++){
//       if(i%j==0)
//         divisors[i]+=2;

//     }
//     j--;
//     if(j*j==i)
//       divisors[i]--;
//   }
// }
int32_t main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

  int t=1;
  divisor();
  cin>>t;
  while(t--)
  {
    int x;
    cin>>x;
    cout<<divisors[x]<<'\n';
  }
  return 0;
}