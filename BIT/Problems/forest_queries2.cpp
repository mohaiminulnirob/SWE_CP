#include<bits/stdc++.h>

using namespace std;
#define int long long 
const int  mx=1e3+50;
int BIT[mx][mx];
int arr[mx][mx];
string s[1005];
int n,m;

int getSum(int i,int j)
{ 
	int sum = 0; 
    int j1;
	while (i>0)
	{
		j1=j;
		while(j1>0){
			sum+=BIT[i][j1];
			j1-=j1 & (-j1);
		}

		i-= i & (-i);
	}
	return sum;
}

void updateBIT(int x, int y, int val) {
  int y1;
  while (x <= n) {
    y1 = y;
    while (y1 <= n) {
      BIT[x][y1] += val;
      y1 += (y1 & -y1);
    }
    x += (x & -x);
  }
}

void constructBIT()
{
	for(int i=1; i<=n; i++)
		for(int j=1;j<=n;j++)
			BIT[i][j]=0;

	for(int i=1; i<=n; i++)
		for(int j=1;j<=n;j++)
		    updateBIT(i,j,arr[i][j]);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
    	cin>>s[i];
    	for(int j=0;j<n;j++){
    		if(s[i][j]=='*')
    			arr[i+1][j+1]=1;
    	}
    }
    constructBIT();
    while(q--){
    	int k;
    	cin>>k;
    	if(k==1){
    		int x,y;
    		cin>>x>>y;
    		if(s[x-1][y-1]=='*'){
    			s[x-1][y-1]='.';
    			updateBIT(x,y,(-1));
    		}
    		else if(s[x-1][y-1]=='.'){
    			s[x-1][y-1]='*';
    			updateBIT(x,y,1);
    		}
    	}
    	else{
    	   int x1,y1,x2,y2;
    	   cin>>x1>>y1>>x2>>y2;
    	   int ans=getSum(x2,y2)-getSum(x1-1,y2)-getSum(x2,y1-1)+getSum(x1-1,y1-1);
         cout<<ans<<'\n';
      }
    }
	return 0;
}