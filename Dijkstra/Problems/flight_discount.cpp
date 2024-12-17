#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
const int N = 1e5 + 9;

map<int, vector<pair<int, ll>>> adjlist;
ll dis[2][N]; 
int n, m;

void dijkstra(int src) {
    memset(dis, 0x3f, sizeof(dis)); 
    dis[0][src] = dis[1][src] = 0; 
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    pq.push({0, src, 1}); 

    while (!pq.empty()) {
        ll d = get<0>(pq.top());
        int u = get<1>(pq.top());
        int coupon = get<2>(pq.top()); 
        pq.pop();

        if (dis[!coupon][u] < d) continue;

        for (auto v : adjlist[u]) {
            int node = v.first;
            ll weight = v.second;

            if (coupon) {
                if (dis[0][node] > d + weight) {
                    dis[0][node] = d + weight;
                    pq.push({d + weight, node, 1});
                }
                if (dis[1][node] > d + weight / 2) {
                    dis[1][node] = d + weight / 2;
                    pq.push({d + weight / 2, node, 0});
                }
            } else { 
                if (dis[1][node] > d + weight) {
                    dis[1][node] = d + weight;
                    pq.push({d + weight, node, 0});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        adjlist[x].push_back({y, z});
    }

    int src = 1;
    dijkstra(src);
    cout << min(dis[0][n], dis[1][n]) << "\n";

    return 0;
}
