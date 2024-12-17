#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define sz 26

struct trinode {
    struct trinode* child[sz];
    bool isEnd;
};

struct trinode* getnode() {
    struct trinode* pnode = new trinode;
    pnode->isEnd = false;
    for (int i = 0; i < sz; i++) {
        pnode->child[i] = NULL;
    }
    return pnode;
}

void insert(struct trinode* root, string s) {
    struct trinode* t = root;
    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - 'a';
        if (!t->child[d]) 
            t->child[d] = getnode();
        t = t->child[d];
    }
    t->isEnd = true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    string s;
    int k;
    cin >> s >> k;

    struct trinode* root = getnode();
    for (int i = 0; i < k; i++) {
        string word;
        cin >> word;
        insert(root, word);
    }

    int n = s.size();
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) continue;

        struct trinode* t = root;
        for (int j = i; j < n; j++) {
            int d = s[j] - 'a';
            if (!t->child[d]) break;
            t = t->child[d];
            if (t->isEnd) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
