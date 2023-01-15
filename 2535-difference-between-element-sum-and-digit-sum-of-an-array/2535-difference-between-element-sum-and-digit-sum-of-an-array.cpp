class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int digitSum,sum,i,n;
        n = nums.size();
        
        sum = 0;
        for(i=0 ; i<n ; i++){
            sum += nums[i];
        }
        
        digitSum = 0;
        for(i=0 ; i<n ; i++){
            while(nums[i] > 0){
                digitSum += nums[i]%10;
                nums[i] /= 10;
            }
        }
        
        return abs(sum - digitSum);        
    }
};