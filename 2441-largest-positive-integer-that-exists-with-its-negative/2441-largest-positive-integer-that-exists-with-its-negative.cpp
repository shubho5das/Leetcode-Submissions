class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n,i,j,ans;
        n = nums.size();
        
        ans = -1;
        for(i=0 ; i<n ; i++){
            if(nums[i] > 0){
                bool negativeExists = false;
                for(j=0 ; j<n ; j++){
                    if(nums[j] == (-1 * nums[i])){
                        negativeExists = true;
                        break;
                    }
                }
                
                if(negativeExists){
                    ans = max(ans,nums[i]);
                }
            }
        }
        
        return ans;        
    }
};