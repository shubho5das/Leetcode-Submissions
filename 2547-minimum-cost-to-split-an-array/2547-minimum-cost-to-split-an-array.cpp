#define inf 1000000000000 // 1e12

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        long long n,i,j,trimmedLength;
        n = nums.size();
        
        vector<long long> dp(n+5);
        // Base Case
        dp[n] = 0;
        dp[n-1] = k;
        
        // General Case
        for(i=(n-2) ; i>=0 ; i--){
            dp[i] = inf;
            
            trimmedLength = 0;
            unordered_map<long long, long long> freq;
            for(j=i ; j<=(n-1) ; j++){
                freq[nums[j]]++;
                
                if(freq[nums[j]] == 2){
                    trimmedLength += 2;
                }
                else if(freq[nums[j]]  >= 3){
                    trimmedLength += 1;
                }
                
                dp[i] = min(dp[i],(k + trimmedLength + dp[j+1]));
            }                
        }
        
        return dp[0];        
    }
};  