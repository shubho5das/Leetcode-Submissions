class Solution {
public:
    long long findCost(vector<int> &nums,vector<int> &cost,long long n,long long x){
        // Cost to convert nums[] --> [x,x,x,....]
        long long i,totalCost;
        
        totalCost = 0;
        for(int i=0 ; i<n ; i++){
            if((nums[i] - x) >= 0){
                totalCost += ((nums[i] - x) * cost[i]);    
            }
            else{
                totalCost += ((x - nums[i]) * cost[i]);    
            }            
        }
        
        return totalCost;
    
    }
    
    long long minCost(vector<int> &nums, vector<int> &cost) {
        long long s,e,mid,n,currentCost,prevCost,nextCost,ans;
        n = nums.size();
        
        ans = -1;        
        s = 0, e = 100000000;        
        while(s <= e){
            mid = s + (e-s)/2;
            
            currentCost = findCost(nums,cost,n,mid);
            prevCost = findCost(nums,cost,n,mid-1);
            nextCost = findCost(nums,cost,n,mid+1);
            
            if(currentCost <= prevCost && currentCost <= nextCost){
                ans = currentCost;
                break;
            }
            
            if(currentCost <= prevCost && nextCost <= currentCost){
                s = (mid + 1);
            }
            else{
                e = (mid - 1);
            }
        }
        
        return ans;        
    }
};