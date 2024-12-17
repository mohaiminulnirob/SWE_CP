#include <bits/stdc++.h>
using namespace std;
const int N=2e6+9;
#define int long long
int n,q,k;
int current_answer;
int cnt[N];
int answers[N];
int BLOCK_SIZE;
int arr[N];
pair<pair<int, int>, int> queries[N];

inline bool mo_cmp(const pair<pair<int, int>,int>&x,
        const pair<pair<int,int>,int>&y)
{
    int block_x=x.first.first/BLOCK_SIZE;
    int block_y = y.first.first/BLOCK_SIZE;
    if(block_x != block_y)
        return block_x<block_y;
    return x.first.second<y.first.second;
}

inline void add(int x)
{
    current_answer+=cnt[x^k];
    cnt[x]++;
}

inline void remove(int x)
{
    cnt[x]--;
    current_answer-=cnt[x^k];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    cin>>n>>q>>k;
    BLOCK_SIZE =1ll*(sqrt(n));

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]^=arr[i-1];
    }

    for(int i=0;i<q;i++) {
        cin>>queries[i].first.first >> queries[i].first.second;
        queries[i].first.first--;
        queries[i].second = i;
    }

    sort(queries, queries + q, mo_cmp);

    // int mo_left = queries[0].first.first, mo_right = queries[0].first.first;
    // current_answer=arr[mo_left];
    // cnt[arr[mo_left]]=1;
    int mo_left=0, mo_right=0;
    current_answer=0;
    cnt[0]++;

    for(int i=0;i<q;i++){
        int left=queries[i].first.first;
        int right=queries[i].first.second;

        while(mo_right<right) {
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_right>right) {
            remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left<left) {
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left>left) {
            mo_left--;
            add(arr[mo_left]);
        }

        answers[queries[i].second]=current_answer;
        //cout<<current_answer<<'\n';
    }

    for(int i=0;i<q;i++)
        cout<<answers[i]<<'\n';

    return 0;
}
