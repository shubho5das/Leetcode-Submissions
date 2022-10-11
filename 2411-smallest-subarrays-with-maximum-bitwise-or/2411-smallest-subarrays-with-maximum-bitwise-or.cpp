class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n,i,j,len;
        n = nums.size();
        
        vector<int> leftmostOneOccurence(32,-1);
        vector<int> solution(n);
        for(i=(n-1) ; i>=0 ; i--){
            // Updating leftmostOneOccurence[]
            j = 0;
            while(nums[i] > 0){
                if(nums[i]%2 == 1){
                    leftmostOneOccurence[j] = i;
                }
                nums[i] /= 2;
                j++;
            }
                                    
            // Determining length of subarray[i,..], having max OR value
            len = 1;
            for(j=0 ; j<32 ; j++){
                if(leftmostOneOccurence[j] != -1){
                    len = max(len,(leftmostOneOccurence[j] - i + 1));
                }
            }
                        
            solution[i] = len;
        }
        
        return solution;
    }
};