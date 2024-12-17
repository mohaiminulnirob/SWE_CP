#include<bits/stdc++.h>
using namespace std;

const int N=2e7+5;
int leastPrime[N];
int divCount[N];
int res[N];
int resSum[N];

void leastPrimeDivisor(){
    for(int i=2;i*i<N;i++){
        if(leastPrime[i]!=0)
            continue;
        for(int j=i;j<N;j+=i){
            leastPrime[j]=i;
        }
    }
    for(int i=2;i<N;i++){
        if(!leastPrime[i])
            leastPrime[i]=i;
    }
}
void divisorsCount(){
    divCount[1]=1;
    for(int i=2;i<N;i++){
        int count=0,j=i;
        while(j%leastPrime[i]==0){
            count++;
            j/=leastPrime[i];
        }
        count++;
        divCount[i]=divCount[j]*count;
    }
}
void determineResult(){
    res[0]=0;
    for(int i=1;i<N;i++){
        int l=i-divCount[i];
        if(l==0 || resSum[i-1]-resSum[l-1]<divCount[i])
            res[i]=1;
        else res[i]=0;
        resSum[i]=resSum[i-1]+res[i];
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    leastPrimeDivisor();
    divisorsCount();
    determineResult();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(res[n]==1)
            cout<<"Ada"<<'\n';
        else cout<<"Vinit"<<'\n';
    }
    return 0;
}

