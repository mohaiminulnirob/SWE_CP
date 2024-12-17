#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int N,M;
void computeLPSArray(int pat[],int lps[]){
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

void KMPSearch(int pat[],int txt[])
{
	int lps[M];
	computeLPSArray(pat,lps);
	int i=0;
	int j=0;
	int init=1;
	int diff;
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

	
	// for(int i=0;i<M;i++){
	// 	cout<<lps[i]<<" ";
	// }
	// cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t=1;;
    //cin>>t;
    while(t--){
    	ans.clear();
    	cin>>N>>M;
    	//cout<<M<<'\n';
    	int pat[M];
    	int txt[N];
    	int a[N];
    	int b[M];
    	for(int i=0;i<N;i++){
    		cin>>a[i];
    	}
    	for(int i=0;i<M;i++){
    		cin>>b[i];
    	}
    	int ans1;
    	if(M==1)
    		ans1=N;
    	else if(N<M)
    		ans1=0;
    	else{

    	for(int i=0;i<N-1;i++){
    		txt[i]=a[i+1]-a[i];
    		//cout<<txt[i]<<" ";

    	}
    	//cout<<'\n';
    	for(int i=0;i<M-1;i++){
    		pat[i]=b[i+1]-b[i];
    		//cout<<pat[i]<<" ";
    	}

        //cout<<'\n';
        M--;N--;
    	KMPSearch(pat,txt);
    	ans1=ans.size();
        }
    	cout<<ans1<<'\n';
    }
   return 0;
}