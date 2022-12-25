class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n,m,i,j,sum,maxLen;
        n = nums.size();
        m = queries.size();
        
        // 1
        sort(nums.begin(),nums.end());
        for(i=1 ; i<n ; i++){
            nums[i] = (nums[i] + nums[i-1]);
        }
        
        // 2
        vector<int> solution(m);
        for(i=0 ; i<m ; i++){
            sum = queries[i];
            maxLen = 0;
            for(j=0 ; j<n ; j++){
                if(nums[j] <= sum){
                    maxLen = (j+1);    
                }                
            }
            
            solution[i] = maxLen;            
        }
        
        return solution;
    }
};