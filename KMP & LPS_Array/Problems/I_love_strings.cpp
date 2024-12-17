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

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        string txt,pat;
        cin>>txt;
        int q;
        cin>>q;
        while(q--){
        ans.clear();
        cin>>pat;
        KMPSearch(pat,txt);
        if(ans.size()>0){
           cout<<"y"<<'\n';
        }
        else cout<<"n"<<'\n';
        }
    }
   return 0;
}