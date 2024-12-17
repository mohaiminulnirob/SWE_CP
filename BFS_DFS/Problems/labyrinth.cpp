#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll
#define endl '\n'
 
const ll mod = 1000000007;
 
// 0-up 1-right 2-down 3-left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string step = "URDL";
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    pair<int, int> start, end;
    char grid[n][m];
    bool visited[n][m];
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            visited[i][j] = false;
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }
 
    visited[start.first][start.second] = true;
    int prevstep[n][m];
 
    queue<pair<int, int>> q;
    q.push(start);
 
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            pair<int, int> v = make_pair(u.first + dx[i], u.second + dy[i]);
            if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
                continue;
            if (grid[v.first][v.second] == '#')
                continue;
            if (visited[v.first][v.second])
                continue;
            visited[v.first][v.second] = true;
            prevstep[v.first][v.second] = i;
            q.push(v);
        }
    }
 
    if (visited[end.first][end.second]){
        cout << "YES" << endl;
        vector<int> steps;
        while (end != start){
            int p = prevstep[end.first][end.second];
            steps.push_back(p);
            end = make_pair(end.first - dx[p], end.second - dy[p]);
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for (char c : steps){
            cout << step[c];
        }
    }
    else{
        cout << "NO" << endl;
    }
 
    return 0;
}
