#include<bits/stdc++.h>

using namespace std;
#define int long long 
const int N=1e3+30;
int BIT[N][N];
int arr[N][N];
int n=1001,m=1001;

int getSum(int i,int j)
{ 
	int sum=0; 
  int j1;
	while(i>0)
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

void updateBIT(int x,int y,int val) {
  int y1;
  while(x<=n) {
    y1=y;
    while(y1 <= m) {
      BIT[x][y1]+=val;
      y1+=y1 & (-y1);
    }
    x+= x & (-x);
  }
}

void constructBIT()
{
	for(int i=1; i<=n; i++)
		for(int j=1;j<m;j++)
			BIT[i][j]=0;

	for(int i=1; i<n; i++)
		for(int j=1;j<m;j++)
		    updateBIT(i,j,arr[i][j]);
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
    int cs=0;
    while(t--)
    {
      memset(BIT,0,sizeof(BIT));
      memset(arr,0,sizeof(arr));
      int q;
      cin>>q;
      cs++;
      cout<<"Case "<<cs<<":"<<'\n';
      while(q--){
        int k;
        cin>>k;
        if(k==0){
          int x,y;
          cin>>x>>y;
    	      if(!arr[x+1][y+1])
        		updateBIT(x+1,y+1,1);
        		arr[x+1][y+1]=1;

        }   
        else{
            	int x1,x2,y1,y2;
            	cin>>x1>>y1>>x2>>y2;
            	int ans=getSum(x2+1,y2+1)-getSum(x1,y2+1)-getSum(x2+1,y1)+getSum(x1,y1);
            	cout<<ans<<'\n';
        }
      }
      // for(int i=1;i<=10;i++){
      //   for(int j=1;j<=10;j++){
      //     cout<<arr[i][j]<<" ";
      //   }
      //   cout<<'\n';
      // }
    }
	return 0;
}