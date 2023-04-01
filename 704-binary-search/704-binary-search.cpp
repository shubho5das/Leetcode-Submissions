class Solution {
public:
    int search(vector<int>& nums, int target) {
        long long n,s,e,mid,idx;
        n = nums.size();
        
        s = 0, e = (n-1), idx = 0;
        while(s <= e){
            mid = s + (e-s)/2;
            
            if(target <= nums[mid]){
                idx = mid;
                e = (mid - 1);
            }
            else{
                s = (mid + 1);
            }
        }
        
        return (nums[idx] == target)? idx : -1;    
    }
};