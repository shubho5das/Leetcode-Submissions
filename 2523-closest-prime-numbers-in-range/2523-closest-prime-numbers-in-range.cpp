#define inf 1000000000

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        long long i,j,n,currentDiff,minDiff;
        n = right;
        
        // Sieve
        vector<bool> isPrime(n+5,false);
        for(i=3 ; i<=n ; i+=2){
            isPrime[i] = true;
        }
        
        for(i=3 ; i<=n ; i+=2){
            if(isPrime[i]){
                for(j=(i*i) ; j<=n ; j=(j+i)){
                    isPrime[j] = false;
                }
            }
        }
        
        isPrime[2] = true;
        isPrime[1] = false;
        isPrime[0] = false;
        
        // 1
        vector<int> primes;
        for(i=left ; i<=right ; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }                        
        }
        
        if(primes.size() <= 1){
            return {-1,-1};
        }
        
        
        minDiff = inf;
        vector<int> solution = {-1,-1};        
        
        for(i=0 ; i<(primes.size() - 1) ; i++){
            currentDiff = (primes[i+1] - primes[i]);
            if(currentDiff < minDiff){
                solution = {primes[i],primes[i+1]};
                minDiff = currentDiff;
            }            
        }
        
        return solution;
    }
};