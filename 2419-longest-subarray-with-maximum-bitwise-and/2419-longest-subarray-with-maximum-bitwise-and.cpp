class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i,j,n,len,mx,currentLength,maxLength;
        n = nums.size();
        
        mx = -1;
        for(i=0 ; i<n ; i++){
            mx = max(mx,nums[i]);
        }
                                
        maxLength = -1;
        currentLength = 0;
        for(i=0 ; i<n ; i++){
            if(nums[i] == mx){
                currentLength++;
                maxLength = max(maxLength,currentLength);
            }
            else{
                currentLength = 0;
            }
        }
        
        return maxLength;
    }
};