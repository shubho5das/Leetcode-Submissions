class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int i,j,n,sum;
        n = nums.size();
        
        for(i=0 ; i<=(n-2) ; i++){
            sum = (nums[i] + nums[i+1]);
            for(j=(i+1) ; j<=(n-2) ; j++){
                if((nums[j] + nums[j+1]) == sum){
                    return true;                    
                }
            }
        }
        
        return false;
    }
};