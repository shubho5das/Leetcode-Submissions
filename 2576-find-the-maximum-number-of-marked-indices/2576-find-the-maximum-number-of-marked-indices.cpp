class Solution {
public:
    bool check(vector<int> &nums, int n, int k){
        int i,j;
        
        i = 0; j = (n-k);
        for( ; i<k ; i++, j++){
            if( !(nums[j] >= 2*nums[i]) ){
                return false;
            }
        }
        
        return true;
    }
    
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n,i,s,e,mid,noOfPairs,ans;
        n = nums.size();
        
        // 1
        sort(nums.begin(),nums.end());
        
        // 2
        noOfPairs = -1;
        s = 0, e = n/2;
        while(s <= e){
            mid = s + (e-s)/2;            
            
            if(check(nums,n,mid) == true){
                noOfPairs = mid;
                s = (mid + 1);
            }
            else{
                e = (mid - 1);
            }
        }
        
        ans = (noOfPairs * 2);
        return ans;
    }
};