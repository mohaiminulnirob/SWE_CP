#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
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


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    while(t--){
        string pat;
        cin>>pat;
        int M=pat.length();
        int lps[M];
        computeLPSArray(pat,M,lps);
        if(lps[M-1]>=(M/2)+1)
            cout<<"YES\n"<<pat.substr(0,lps[M-1])<<'\n';
        else cout<<"NO"<<'\n';
    }
   return 0;
}