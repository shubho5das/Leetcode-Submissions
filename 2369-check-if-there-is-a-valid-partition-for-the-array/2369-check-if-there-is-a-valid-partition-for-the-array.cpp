class Solution {
public:
    bool validPartition(vector<int>& nums) {
        long long i,n;
        n = nums.size();
        
        vector<bool> dp(n);
        
        // Base Case
        dp[0] = false;
        
        dp[1] = (nums[1] == nums[0])? true : false;
                
        if(n >= 3 && (nums[2] == nums[1]) && (nums[1] == nums[0])){
            dp[2] = true;
        }
        else if(n >= 3 && (nums[2] == (nums[1] + 1)) && (nums[1] == (nums[0] + 1))){
            dp[2] = true;
        }
        else{
            dp[2] = false;
        }
        
        // General Case
        for(i=3 ; i<n ; i++){
            dp[i] = false;
            
            // Check 1
            if(nums[i] == nums[i-1] && dp[i-2] == true){
                dp[i] = true;
            }
                        
            // Check 2
            if(nums[i] == nums[i-1] && nums[i-1] == nums[i-2] && dp[i-3] == true){
                dp[i] = true;
            }
            
            // Check 3
            if(nums[i] == (nums[i-1] + 1) && nums[i-1] == (nums[i-2] + 1) && dp[i-3] == true){
                dp[i] = true;
            }
        }
        
        
        return dp[n-1];
    }
};