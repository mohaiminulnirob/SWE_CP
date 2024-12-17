#include<bits/stdc++.h>
using namespace std;

int V,E;
long long int dis[205];
bool imp[205];

void bellmanford(int src,long long graph[][3])
{
    for(int i=0;i<=V;i++)
    {
        dis[i]=INT_MAX;
        imp[i]=false;
    }

    dis[src]=0;
    for (int i = 0; i < V - 1; i++) {

		for (int j = 0; j < E; j++) {
			if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] <
							dis[graph[j][1]])
                {
                    dis[graph[j][1]] =
				dis[graph[j][0]] + graph[j][2];
                }

		}
	}

	for (int i = 0; i < E; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (dis[x] != INT_MAX &&
				dis[x] + weight < dis[y])
				imp[y]=true;
	}
}

int main()
{
    int t,cs=0;
    cin>>t;
    while(t--)
    {
        cs++;
        cin>>V;
        int a[V+1];
        for(int i=1;i<=V;i++)
        {
            cin>>a[i];
        }
        cin>>E;
        long long graph[E][3];
        for(int i=0;i<E;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[i][0]=x;
            graph[i][1]=y;
            long long d=a[y]-a[x];
            d=d*d*d;
            graph[i][2]=d;
        }
        bellmanford(1,graph);
        int q;
        cin>>q;
        cout<<"Case "<<cs<<": "<<endl;
        while(q--)
        {
            int c;
            cin>>c;
            if(dis[c]<3 || imp[c]==true || dis[c]==INT_MAX)
                cout<<"?"<<endl;
            else cout<<dis[c]<<endl;
        }
    }
    return 0;
}
