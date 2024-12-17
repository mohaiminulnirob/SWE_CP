#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+9;
int BITree[N];
int arr[N];

int getSum(int index)
{ 
	int sum=0; 
	index=index+1;

	while(index>0)
	{
		sum+=BITree[index];

		index-=index & (-index);
	}
	return sum;
}

void updateBIT(int n,int index,int val)
{
	index=index+1;

	while(index <= n)
	{
	BITree[index]+=val;

	index+=index & (-index);
	}
}

void constructBITree(int n)
{
	for(int i=1;i<=n;i++)
		BITree[i]=0;

	for(int i=0;i<n;i++)
		updateBIT(n,i,arr[i]);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

	return 0;
}
/*
BIT

Matrix Summation(2G spoj)
Points in rectangle(lightoj)
Forest Queries(cses)
Forest Queries II(cses)
*/