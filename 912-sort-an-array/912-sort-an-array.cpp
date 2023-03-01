#define inf 1000000000

class Solution {
public:    
    vector<int> sortArray(vector<int>& nums) {
        int i,n,val,minValue,maxValue;
        n = nums.size();
        
        // Counting sort
        unordered_map<int,int> freq;
        minValue = inf, maxValue = -inf;
        for(i=0 ; i<n ; i++){
            freq[nums[i]]++;
            minValue = min(minValue,nums[i]);
            maxValue = max(maxValue,nums[i]);
        }
        
        vector<int> solution;
        for(val=minValue ; val<=maxValue ; val++){
            for(i=0 ; i<freq[val] ; i++){
                solution.push_back(val);
            }
        }
        
        return solution;
    }
};