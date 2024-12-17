#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
int distinct[N];

bool compare(pair<pair<int, int>, int> a1, pair<pair<int, int>, int> a2) {
    if (a1.first.first != a2.first.first) {
        return a1.first.first < a2.first.first;
    }
    return a1.first.second < a2.first.second;
}

vector<int> lcp_construction(string s, vector<int> p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

void suffix_array(string s, vector<int>& SA, vector<int>& LCP) {
    int n = s.size();
    vector<int> p(n), c(n);
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first == a[i - 1].first) {
            c[p[i]] = c[p[i - 1]];
        } else {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end(), compare);

        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }

    SA = p;
    LCP = lcp_construction(s, p);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    s += "$";
    int n = s.size();

    vector<int> SA, LCP;
    suffix_array(s, SA, LCP);

    int q;
    cin >> q;
    //cout<<q<<'\n';
    while (q--) {
        //cout<<q<<'\n';
        int x;
        cin >> x;
        //int n = s.size();
        for (int i = 1; i < n; i++) {
        int len = n - SA[i] - 1; 
        int distinct_count = len - LCP[i - 1];
        if (x <= distinct_count) {
            cout<<s.substr(SA[i], LCP[i - 1] + x)<<'\n';
            break;
        }
        x -= distinct_count;
    }
    }
    return 0;
}
