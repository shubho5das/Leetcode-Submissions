class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long double n,i,j;
        n = nums.size();
        
        unordered_set<long double> presentInNums;
        for(i=0 ; i<n ; i++){
            presentInNums.insert(nums[i]);
        }
                
        vector<long double> dp(target+1,0);
        sort(nums.begin(),nums.end());
        
        for(i=0 ; i<=target ; i++){
            dp[i] = 0;
            
            if(presentInNums.find(i) != presentInNums.end()){
                dp[i] += 1;
            }
            
            for(j=0 ; j<n ; j++){
                if((i-nums[j]) >= 0){
                   dp[i] += dp[i-nums[j]]; 
                }
                else{
                    break;
                }
            }                        
        }
        
        return dp[target];                
    }
};