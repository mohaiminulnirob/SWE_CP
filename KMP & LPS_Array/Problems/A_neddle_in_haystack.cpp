#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846264338327
#define pb push_back
const int N=2e5+9;
const int mod=1e9+7;
vector<int>ans;

void lpsArray(string pat,int M,int lps[]){
	int len=0;
	lps[0]=0;
 	int i=1;
	while(i<M){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}
void kmp(string pat,string txt){
	int M=pat.size();
	int N=txt.size();
	int lps[M];
	lpsArray(pat,M,lps);
	int i=0;
	int j=0;
	while((N-i)>=(M-j)) {
		if(pat[j]==txt[i]) {
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

    int t=1,n;
    //cin>>t;
    while(cin>>n){
    	ans.clear();
    	string txt,pat;
    	cin>>pat>>txt;
    	kmp(pat,txt);
    	sort(ans.begin(),ans.end());
    	if(ans.size()>0){
    	    for(auto u:ans){
    		    cout<<u-1<<'\n';
    	    }
    	    if(t)
              cout<<'\n';
        }
    }
   return 0;
}