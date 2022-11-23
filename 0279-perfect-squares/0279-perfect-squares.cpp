#define inf 1000000000

class Solution {
public:
    int numSquares(int n) {
        int i,j;
        
        vector<int> dp(n+5);
        // Base Case
        dp[0] = 0;
        dp[1] = 1; 
        // General Case
        for(i=2 ; i<=n ; i++){
            dp[i] = inf;
            for(j=1 ; j*j<=i ; j++){
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
                
        return dp[n];
    }
};