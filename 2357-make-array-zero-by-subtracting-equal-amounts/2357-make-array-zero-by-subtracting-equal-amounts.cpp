class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n,i,len;
        n = nums.size();
        
        unordered_set<int> P;
        for(i=0 ; i<n ; i++){
            if(nums[i] > 0){
                P.insert(nums[i]);
            }
        }
        
        len = P.size();
        return len;                    
    }
};