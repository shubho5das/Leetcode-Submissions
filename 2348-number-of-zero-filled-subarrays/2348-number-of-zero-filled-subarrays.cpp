class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long i,j,n,len,cnt;
        n = nums.size();
        
        cnt = 0;
        for(i=0 ; i<n ; ){
            if(nums[i] == 0){
                j = i, len = 0;
                while(j<n && nums[j] == 0){
                    len++;
                    j++;
                }
                cnt += ((len)*(len+1))/2;                
                i = j;
            }
            else{
                i++;
            }
        }
        
        return cnt;
    }
};