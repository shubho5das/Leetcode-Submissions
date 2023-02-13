#define inf 1000000000

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int l, int u) {
        long long n,i,j1,j2,s,e,mid,cnt;
        n = nums.size();
        
        // 1
        sort(nums.begin(),nums.end());
        
        // 2
        cnt = 0;
        for(i=0 ; i<n ; i++){       
            j1 = inf, j2 = -inf;
            
            // j1: As left as possible
            s = (i+1), e = (n-1);
            while(s <= e){
                mid = s + (e - s)/2;
                if(nums[i] + nums[mid] >= l){
                    j1 = mid;
                    e = (mid - 1);
                }
                else{
                    s = (mid + 1);
                }
            }
                                    
            // j2: As right as possible
            s = (i+1), e = (n-1);
            while(s <= e){
                mid = s + (e-s)/2;
                if(nums[i] + nums[mid] <= u){
                    j2 = mid;
                    s = (mid + 1);
                }
                else{
                    e = (mid - 1);
                }
            }
                        
            if(j1 <= j2){
                cnt += (j2 - j1 + 1);
            }                          
        }
        
        return cnt;
    }
};