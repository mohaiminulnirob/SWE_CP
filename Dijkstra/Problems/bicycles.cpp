#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, ll>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }

        vector<int> slowness(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> slowness[i];
        }

        vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, INF));

        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> pq;

        dis[1][1] = 0;
        pq.push({0, 1, 1}); 

        while (!pq.empty()) {
            array<ll, 3> top_element = pq.top();
            ll current_dist = top_element[0];
            int node = top_element[1];
            int bike_city = top_element[2];

            pq.pop();

            if (current_dist > dis[node][bike_city]) continue;

            if (dis[node][node] > current_dist) {
                dis[node][node] = current_dist;
                pq.push({current_dist, node, node});
            }

            for (auto edge : adj[node]) {
                 int neighbor = edge.first;
                 int weight = edge.second;

                 ll new_dist = current_dist + weight * slowness[bike_city];
                if (dis[neighbor][bike_city] > new_dist) {
                    dis[neighbor][bike_city] = new_dist;
                    pq.push({new_dist, neighbor, bike_city});
                }
            }
        }

        ll ans = INF;
        for (int bike = 1; bike <= n; bike++) {
            ans = min(ans, dis[n][bike]);
        }

        cout << ans << "\n";
    }

    return 0;
}
