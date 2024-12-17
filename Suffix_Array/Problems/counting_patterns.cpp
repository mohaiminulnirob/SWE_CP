#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int maxN = 1e5 + 5;
int suffixArray[maxN], position[maxN];
int n;
string s;
 
bool compare(pair<pair<int, int>, int>a1,pair<pair<int, int>, int>a2) {
    if (a1.first.first != a2.first.first) {
        return a1.first.first < a2.first.first;
    }
    return a1.first.second < a2.first.second;
}


void suffix_array(){
        int n=s.size();
        vector<int>lcp(n);
        vector<int> p(n);
        vector<int>c(n);
        vector<pair<char, int> > a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {s[i], i};
        }

        sort(a.begin(), a.end());

        for(int i=0;i<n;i++) {
            p[i]=a[i].second;
        }
        c[p[0]]=0;


        for(int i = 1; i < n; i++) {
            if(a[i].first == a[i - 1].first) {
                c[p[i]] =c[p[i-1]];
            } else {
                c[p[i]] =c[p[i-1]] + 1;
            }
        } 
        int k=0;
        while((1 << k) < n) {
        vector<pair<pair<int,int>,int>>a(n);

        for(int i = 0; i < n; i++) {
            a[i]={{c[i],c[(i+(1<<k))%n]},i};
        }

        sort(a.begin(), a.end(), compare);

        for(int i=0;i<n;i++) {
            p[i]=a[i].second;
        }

        c[p[0]] = 0;

        for(int i=1;i<n;i++) {
            if(a[i].first==a[i-1].first) { 
                c[p[i]]=c[p[i-1]];
            } else {
                c[p[i]]=c[p[i-1]]+1;
            }
        }
        k++;
        }
        // for(int i = 1; i <n; i++) {
        // cout << p[i] << " " << s.substr(p[i], n - p[i]-1) <<  endl;
        // }
        //lcp=lcp_construction(s,p);
        //lcp[n-1]=0;
        // for(int i=1;i<n;i++)
        //  cout<<lcp[i]<<" ";
        // n--;
        // int ttl=1ll*(n*(n+1))/2;
        // for(int i=1;i<=n;i++){
        //  ttl-=lcp[i];
        // }
        // cout<<ttl<<'\n';
        for(int i=1;i<=n-1;i++){
            position[p[i]]=i;
        }
        for(int i=1;i<=n-1;i++){
            suffixArray[i]=p[i];
        }

}

int checkPattern(int mid, string& pattern)
{
    int flag = -1, patternSize = pattern.size(),
        suffixStart = suffixArray[mid];
 
    if (n - suffixStart >= patternSize)
        flag = 0;
 
    for (int i = 0; i < min(n - suffixStart, patternSize);i++) {
        if (s[suffixStart + i] < pattern[i])
            return -1;
        if (s[suffixStart + i] > pattern[i])
            return 1;
    }
    return flag;
}
 
void solve(string& pattern)
{
    int left = 1, right = n - 1;
    int answer = -1, l = left, r = right;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int check = checkPattern(mid, pattern);
        if (check == 0) {
            answer = mid;
            r = mid - 1;
        }
        else if (check == 1)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (answer == -1) {
        cout << 0 << endl;
        return;
    }
 
    left = answer, l = left, r = right;
 
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int check = checkPattern(mid, pattern);
        if (check == 0) {
            answer = mid;
            l = mid + 1;
        }
        else if (check == -1)
            l = mid + 1;
        else
            r = mid - 1;
    }
 
    right = answer;
 
    cout << right - left + 1 << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cin>>s;
    string y=s;
    s+="$";
 
    suffix_array();
    n=s.size();
    int t;
    cin>>t;
    vector<string> patterns ;
 
    for(int i=0;i<t;i++){
        string z;
        cin>>z;
        patterns.push_back(z);
    }
    for (auto pattern : patterns) {
        solve(pattern);
    }
}