#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int N=2e5+9;
const int mod=1e9+7;

int32_t main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif 

  int t=1,cs=0;
  cin>>t;
  while(t--)
  {
  	cs++;
  	int n,m;
  	cin>>n>>m;
  	ll xs=0;
  	for(int i=0;i<n;i++){
  		ll sum=0;
  		for(int j=0;j<m;j++){
  			int x;
  			cin>>x;
  			sum+=x;
  		}
        xs^=sum;
  	}
  	cout<<"Case "<<cs<<": ";
  	if(xs)
  		cout<<"Alice"<<'\n';
  	else cout<<"Bob"<<'\n';
   
  }
  return 0;
}