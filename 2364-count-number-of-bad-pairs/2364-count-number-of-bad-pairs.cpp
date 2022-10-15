class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n,i,totalPairs,goodPairs,badPairs;
        n = nums.size();
        
        totalPairs = (n*(n-1))/2;
        
        // Determining the count of goodPairs
        for(i=0 ; i<n ; i++){
            nums[i] = (nums[i] - i);
        }
        
        unordered_map<long long,long long> freq;
        for(i=0 ; i<n ; i++){
            freq[nums[i]]++;
        }
        
        goodPairs = 0;
        for(auto x : freq){
            goodPairs += ((x.second * (x.second - 1))/2);
        }
        
        // Final answer
        badPairs = (totalPairs - goodPairs);
        return badPairs;        
    }
};