class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n,i,reversedValue,ans;
        n = nums.size();
        
        unordered_set<int> solution;
        for(i=0 ; i<n ; i++){
            solution.insert(nums[i]);
            
            string str = to_string(nums[i]);
            reverse(str.begin(),str.end());
            reversedValue = stoi(str);
            solution.insert(reversedValue);
        }
        
        ans = solution.size();
        return ans;
    }
};