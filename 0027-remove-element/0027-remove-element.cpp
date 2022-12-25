class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n,i,j,cnt;
        n = nums.size();
        
        cnt = 0;
        for(i=0 ; i<n ; i++){
            if(nums[i] == val) cnt++;
        }
        
        j = 0;
        for(i=0 ; i<n && j<n; i++){
            while(j<n && nums[j] == val){
                j++;
            }
            
            if(nums[i] == val && j<n){
                swap(nums[i],nums[j]);
            }
            
            j = max(i+1,j);
        }
        
        return (n- cnt);
    }
};