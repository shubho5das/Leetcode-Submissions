class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int i,n,countPositive,countNegative;
        n = nums.size();
        
        countPositive = 0, countNegative = 0;
        for(i=0 ; i<n ; i++){
            if(nums[i] > 0){
                countPositive++;
            }
            else if(nums[i] < 0){
                countNegative++;
            }
        }
        
        return max(countPositive,countNegative);
    }
};