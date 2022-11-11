class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current,i,j,n;
        n = nums.size();
        
        i = 0, j = 0;
        while(j < n){
            if(nums[j] != current){
                nums[i] = nums[j];
                i++;
                
                current = nums[j];
            }
            
            j++;
        }
        
        return i;
    }
};