class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int i,n,maxCount,ans;
        n = nums.size();
        
        // 1
        map<int,int> count;
        for(i=0 ; i<n ; i++){
            count[nums[i]]++;
        }
        
        // 2
        ans = -1;
        maxCount = 0;
        for(auto x : count){
            if(x.first%2 == 0 && x.second > maxCount){
                maxCount = x.second;
                ans = x.first;
            }
        }
        
        return ans;
    }
};