#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
map<int,vector<int>>adj;

vector<int> topologicalSort(int V){
	vector<int>indegree(V,0);
    vector<int>result;
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i=0;i<V;i++){
		for(auto it:adj[i]){
			indegree[it]++;
		}
	}
	for(int i=0;i<V;i++) {
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node=q.top();
		q.pop(); 
		result.pb(node);

		for(auto it:adj[node]){
			indegree[it]--;	
			if(indegree[it]==0)
				q.push(it);
		}
	}

	if(result.size()!=V){
		cout<<"Graph contains cycle!"<<'\n';
		return {};
	}
	return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    
	adj.clear();
	int V,E;
	cin>>V>>E;
	topologicalSort(V);
	return 0;
}
