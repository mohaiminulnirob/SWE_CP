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

void KMPSearch(string pat,string txt)
{
    int M=pat.size();
    int N=txt.size();
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i=0;
    int j=0;
    while((N-i)>=(M-j)) {
        if (pat[j]==txt[i]) {
            j++;
            i++;
        }

        if(j==M) {
            ans.push_back(i-j+1);
            j=lps[j-1];
        }

        else if(i<N && pat[j]!=txt[i]) {
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
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
        ans.clear();
        string txt,pat;
        cin>>txt>>pat;
        int m=pat.length();
        KMPSearch(pat,txt);
        if(ans.size()>0){
            // int n=ans.size();
            // int a[n];
            int i=-1;
            int c=0;
            for(auto u:ans){
                if(i==-1 || u>i+pat.length()-1){
                    c++;
                    i=u;
                }
            }
            cout<<c<<'\n';
        }
        else cout<<"0"<<'\n';
    }
   return 0;
}