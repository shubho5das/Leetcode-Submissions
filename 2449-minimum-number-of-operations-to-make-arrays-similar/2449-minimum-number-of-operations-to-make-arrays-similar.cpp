class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long cnt,i,j,n,diff_i,diff_j,minDiff,e,o;
        n = nums.size();
        
        // 1                
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        
        vector<int> odd, even;
        for(i=0 ; i<n ; i++){
            if(nums[i]%2 == 0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        
        // Determining (even-aligned and odd-aligned) nums[]
        e = 0, o = 0;
        for(i=0 ; i<n ; i++){
            if(target[i]%2 == 0){
                nums[i] = even[e];
                e++;
            }
            else{
                nums[i] = odd[o];
                o++;                
            }
        }
                
        // 2
        i = 0, j = 0, cnt = 0;     
        while(i<n && j<n){
            while(i<n && nums[i] >= target[i]){
                i++;
            }
            
            while(j<n && nums[j] <= target[j]){
                j++;
            }
            
            if(i>=n || j >= n){
                break;
            }
                    
            diff_i = (target[i] - nums[i]);
            diff_j = (nums[j] - target[j]);
            minDiff = min(diff_i,diff_j);
            
            cnt += minDiff/2;            
            nums[i] += minDiff;
            nums[j] -= minDiff;                                    
        }
        
        return cnt;                        
    }
};