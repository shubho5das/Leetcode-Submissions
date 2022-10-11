class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int i,n,cnt;
        n = nums.size();
        
        unordered_set<int> P;
        for(i=0 ; i<n ; i++){
            P.insert(nums[i]);
        }
                
        cnt = 0;
        for(i=0 ; i<n ; i++){
            if((P.find(nums[i] + diff) != P.end()) && (P.find(nums[i] + 2*diff) != P.end())){
                cnt++;
            }
        }
        
        return cnt;
    }
};