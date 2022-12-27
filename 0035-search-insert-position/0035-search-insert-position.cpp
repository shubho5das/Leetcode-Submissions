#define inf 1000000000

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n,i,s,e,mid,idx;
        n = nums.size();
        
        nums.push_back(inf);
        
        s = 0, e = n;
        while(s <= e){
            mid = s + (e-s)/2;
            
            if(nums[mid] < target){
                s = (mid + 1);
            }
            else{
                idx = mid;
                e = (mid - 1);
            }            
        }
        
        return idx;
    }
};