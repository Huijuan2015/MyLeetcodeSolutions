class Solution {
public:
    int countPrimes(int n) {
        //nloglogn
        //https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
        if (n<=2) return 0;
        vector<int> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 0; i<sqrt(n); ++i){
            //从i^2开始~删除i^2+xi
            if(prime[i]){
                for(int j = i*i; j < n; j += i){
                    prime[j] = false;
                }
            }
            
        }
        return count(prime.begin(), prime.end(), true);
    }
};