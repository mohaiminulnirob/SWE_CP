#include <bits/stdc++.h>

using namespace std;

int dx[4]={-2, -2, -1, 1};
int dy[4]={ 1, -1, -2,-2};

int grandy_value[20][20];

int sg(int x,int y)
{
    if((x==1&&y==1))
    {
        return 0;
    }
    if(grandy_value[x][y]!=-1)
    {
        return grandy_value[x][y];
    }
    set<int>s;
    for(int i=0;i<4;i++)
    {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=1&&newy>=1&&newx<=15&&newy<=15)
        {
            s.insert(sg(newx,newy));
        }
    }
    int mex=0;
    while(s.find(mex)!=s.end()) mex++;
    grandy_value[x][y]=mex;
    return grandy_value[x][y];
}


int main()
{
        int n;
        memset(grandy_value,-1,sizeof(grandy_value));
        int tc;
        cin>>tc;
        while(tc--)
        {
		cin>>n;
		int ans=0,x,y;
		for(int i = 1; i <= n; ++ i)
		{
			cin>>x>>y;
			ans^=sg(x,y);
		}
		if(ans) cout<<"First"<<endl;
            else cout<<"Second"<<endl;
        }
	    return 0;
}
