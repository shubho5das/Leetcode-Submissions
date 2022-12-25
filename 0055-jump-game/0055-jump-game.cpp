class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n,i,farthestDistance;
        n = nums.size();
        
        farthestDistance = 0;
        for(i=0 ; i<n ; i++){
            if(i <= farthestDistance){
                farthestDistance = max(farthestDistance,(i + nums[i]));
            }            
        }
        
        return (farthestDistance >= (n-1));
    }
};