#define inf 1000000000

class Solution {
public:
    int longestIdealString(string S, int k) {
        int n,i,j,ans;
        n = S.length();
        
        vector<int> nums(n);
        for(i=0 ; i<n ; i++){
            nums[i] = (int)(S[i] - 'a');
        }
        
        vector<int> maxLengthSoFar(26,-1);                        
        vector<int> dp(n+5);
        
        // Base Case
        dp[0] = 1;
        maxLengthSoFar[nums[0]] = 1;
        
        // General Case
        for(i=1 ; i<n ; i++){
            dp[i] = 1;
            
            for(j=0 ; j<26 ; j++){
                if(maxLengthSoFar[j] != -1 && abs(nums[i] - j) <= k){
                    dp[i] = max(dp[i],(1 + maxLengthSoFar[j]));
                }
            }
            
            maxLengthSoFar[nums[i]] = dp[i];
        }
                    
        ans = -inf;
        for(i=0 ; i<n ; i++){
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};