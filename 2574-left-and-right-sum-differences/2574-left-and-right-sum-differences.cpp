class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n,i;
        n = nums.size();
        
        vector<int> left_sum(n), right_sum(n), solution(n);
        left_sum[0] = 0;
        for(i=1 ; i<n ; i++){
            left_sum[i] = left_sum[i-1] + nums[i-1];
        }
        
        right_sum[n-1] = 0;
        for(i=(n-2) ; i>=0 ; i--){
            right_sum[i] = (right_sum[i+1] + nums[i+1]);
        }
        
        for(i=0 ; i<n ; i++){
            solution[i] = abs(left_sum[i] - right_sum[i]);
        }
        
        return solution;
        
    }
};