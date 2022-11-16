#define inf 1000000000

class Solution {
public:
    
    int f(int s,int e,vector<vector<int>> &dp){
        int minCost,currentCost,i;
        
        // Base Case
        if(s >= e){
            return 0;
        }
                                
        // General Case
        
        // Lookup
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        
        minCost = inf;
        for(i=s ; i<=e ; i++){
            currentCost = (i + max(f(s,i-1,dp),f(i+1,e,dp)));
            minCost = min(minCost,currentCost);
        }
        
        dp[s][e] = minCost;
        return minCost;                        
    }
    
    int getMoneyAmount(int n) {
        int ans;
        
        vector<vector<int>> dp(n+5,vector<int>(n+5,-1));
        ans = f(1,n,dp);
        return ans;                                
    }
};