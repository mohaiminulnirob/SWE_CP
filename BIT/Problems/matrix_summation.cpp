#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N=1e3+30;
int BIT[N][N];
int arr[N][N];
int n,m;

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
      memset(BIT,0,sizeof(BIT));
      memset(arr,0,sizeof(arr));
    	cin>>n;
    	m=n;
        while(1)
        {
        	string s;
        	cin>>s;
        	if(s=="END")
        		break;
        	else if(s=="SET"){
        		int x,y,num;
        		cin>>x>>y>>num;
        		updateBIT(x+1,y+1,num-arr[x+1][y+1]);
        		arr[x+1][y+1]=num;
        	}
            else{
            	int x1,x2,y1,y2;
            	cin>>x1>>y1>>x2>>y2;
            	int ans=getSum(x2+1,y2+1)-getSum(x1,y2+1)-getSum(x2+1,y1)+getSum(x1,y1);
            	cout<<ans<<'\n';
            }
        }
    }
	return 0;
} 