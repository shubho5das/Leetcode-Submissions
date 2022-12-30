class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n,i,j,ans;
        n = prices.size();
        
        vector<int> dp(n+5);
        // Base Case
        dp[n] = 0;
        dp[n-1] = 0;          
        dp[n+2] = 0;
        // General Case
        for(i=(n-2) ; i >= 0 ; i--){            
            dp[i] = 0;
            dp[i] = max(dp[i], (0 + dp[i+1]));
            for(j=(i+1) ; j<n ; j++){
                dp[i] = max(dp[i], ((prices[j] - prices[i]) + dp[j+2]));
            }
        }        
        
        return dp[0];
    }
};