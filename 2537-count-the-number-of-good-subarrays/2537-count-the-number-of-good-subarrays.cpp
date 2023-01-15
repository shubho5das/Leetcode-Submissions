class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n,i,s,e,cnt,ans;
        n = nums.size();
        
        unordered_map<int,int> freq;        
        
        
        ans = 0, cnt = 0, e = -1;
        for(s=0 ; s<n ; s++){
            // 1
            while(e < n && cnt < k){
                e++;
                
                cnt -= ((freq[nums[e]]) * (freq[nums[e]] - 1))/2;
                freq[nums[e]]++;
                cnt += ((freq[nums[e]]) * (freq[nums[e]] - 1))/2;                                                
            }
            
            // 2
            if(cnt >= k){
                ans += (n - e);
            }
                        
            //3
            cnt -= ((freq[nums[s]]) * (freq[nums[s]] - 1))/2;
            freq[nums[s]]--;
            cnt += ((freq[nums[s]]) * (freq[nums[s]] - 1))/2;                         
        }
        
        return ans;
    }
};