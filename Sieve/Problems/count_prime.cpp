class Solution {
public:
    int countPrimes(int n) {
        bool is_prime[n+1];
        for(int i=2;i<=n;i++)
           is_prime[i]=true;
        for(int i=2;i*i<=n;i++){
            if(is_prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    is_prime[j]=false;

                }
            }
        }
        int c=0;
        for(int i=2;i<n;i++){
            if(is_prime[i])
            c++;
        }
        return c;
        
    }
};