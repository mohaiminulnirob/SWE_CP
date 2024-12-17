#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[30];
int grundy[100005];
int n,m;

int calculateMex(set<int>s){
	int mex=0;
	while(s.find(mex)!=s.end())
		mex++;
	return mex;
}

int calculateGrundy(int x){
	if(x<a[0])
		return 0;
	else if(grundy[x]!=-1)
		return grundy[x];
	set<int>s;
	for(int i=0;i<m;i++){
		if(x>=a[i])
			s.insert(calculateGrundy(x-a[i]));
	}
	grundy[x]=calculateMex(s);
	return grundy[x];
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
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(grundy,-1,sizeof(grundy));
        cin>>n>>m;
        int xs=0;
        for(int i=0;i<m;i++)
        	cin>>a[i];
        for(int i=0;i<n;i++)
        {
        	int x;
            cin>>x;
            xs^=calculateGrundy(x);
        }
        if(!xs)
        	cout<<"Vinit"<<'\n';
        else cout<<"Ada"<<'\n';
	}
	return 0;
}