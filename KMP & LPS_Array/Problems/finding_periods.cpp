#include <bits/stdc++.h>
using namespace std;
int c=1;
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
        c=1;
        string txt,pat;
        cin>>pat;
        int M=pat.size();
        int lps[M];
        computeLPSArray(pat, M, lps); 
        int len =lps[M-1];
        vector<int>ans;
        while(len>0){
            ans.push_back(M-len);
            len=lps[len-1];
        }
        ans.push_back(M);
        sort(ans.begin(),ans.end());
        for(auto u:ans)
            cout<<u<<" ";
        cout<<'\n';
    }
    
   return 0;
}
