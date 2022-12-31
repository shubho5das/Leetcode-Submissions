class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n,i,s,e,diff,len,cnt;;
        n = nums.size();
        
        cnt = 0;
        for(i=0 ; i<=(n-2) ; i++){
            s = i, e = (i+1);
            diff = (nums[e] - nums[s]);
            while((e+1) < n && (nums[e+1] - nums[e]) == diff){
                e++;
            }
            
            len = (e - s + 1);
            cnt += (len - 2);
        }
        
        return cnt;        
    }
};