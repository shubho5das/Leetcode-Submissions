#define mod 1000000007

class Solution {
public:
    int numTilings(int n) {
        int i,j;
        
        vector<int> dp(n+5,-1);
        
        // Base Case
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;    
        // General Case
        for(i=3 ; i<=n ; i++){
            dp[i] = 0;            
            // Placing the 2*1 Domino vertical
            dp[i] = (dp[i]%mod + dp[i-1]%mod) % mod;
            // Placing the 2*1 Domino horizontal
            dp[i] = (dp[i]%mod + dp[i-2]%mod) % mod;
            // Placing the L-shaped Tromino
            for(j=(i-3) ; j>=0 ; j--){
                dp[i] = (dp[i]%mod + dp[j]%mod) % mod;                
            }                        
            // Placing the L-shaped Tromino reversed
            for(j=(i-3) ; j>=0 ; j--){
                dp[i] = (dp[i]%mod + dp[j]%mod) % mod;                
            }                        
        }
        
        return dp[n];        
    }
};