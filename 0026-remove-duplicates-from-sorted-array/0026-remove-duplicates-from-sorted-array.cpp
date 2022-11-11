class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current,i,j,n;
        n = nums.size();
        
        current = -1000, j = 0;
        for(i=0 ; i<n ; i++){
            if(nums[i] != current){
                nums[j] = nums[i];
                current = nums[i];
                j++;
            }
        }
        
        return j;
    }
};