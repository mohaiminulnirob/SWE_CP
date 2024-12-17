#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int mod=1e9+7;
const int N=2e5+9;
void computeLPSArray(string pat,int M,int lps[]){
  int len=0;
  lps[0]=0;
  int i=1;
  while(i<M) {
    if(pat[i]==pat[len]) {
      len++;
      lps[i]=len;
      i++;
    }
    else{
      if(len!=0) {
        len=lps[len-1];
      }
      else{
        lps[i]=0;
        i++;
      }
    }
  }
}

int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif 

  int t=1;
  //cin>>t;
  while(t--)
  {

    string s;
    cin>>s;
    int M=s.size();
    int lps[M],ans=0;
    computeLPSArray(s,M,lps);
    int len=lps[M-1];
    while(len>0){
      for(int i=0;i<M-1;i++){
        //cout<<lps[i]<<'\n';
        if(lps[i]==len){
          for(int j=i-lps[i]+1;j<=i;j++){
            cout<<s[j];
          }
          cout<<'\n';
          ans=1;
          break;
        }
      }
      len=lps[len-1];
      if(ans)
        break;
    }
      if(!ans)
         cout<<"Just a legend"<<'\n';
  }

  return 0;
}