class Solution {
public:
    long long countSubarraysInGoodArray(vector<int> &arr,int minK,int maxK){
        // GoodArray: array having elements ∈ [minK,maxK]
        long long i,n,s,e,currentCnt,totalCnt;
        n = arr.size();
        
        // 1
        vector<int> index_minK(n,n);  // First occurence of minK in [i..]
        vector<int> index_maxK(n,n);  // First occurence of maxK in [i..]
        
        index_minK[n-1] = (arr[n-1] == minK)? (n-1) : n;
        index_maxK[n-1] = (arr[n-1] == maxK)? (n-1) : n;        
        for(i=(n-2) ; i>=0 ; i--){
            index_minK[i] = (arr[i] == minK)? i : index_minK[i+1];
            index_maxK[i] = (arr[i] == maxK)? i : index_maxK[i+1];
        }
        
        // 2
        totalCnt = 0;
        for(i=0 ; i<n ; i++){
            s = i;
            e = max(index_minK[i],index_maxK[i]);
            currentCnt = (n - e);   // [s,e→]    (ie, [s,e],[s,e+1],[s,e+2],...[s,(n-1)] )
            totalCnt += currentCnt;
        }
        
        return totalCnt;
    }
    
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK){
        long long n,i,j,cnt;
        n = nums.size();
            
        cnt = 0;
        for(i=0 ; i<n ; ){
            if(nums[i] >= minK && nums[i] <= maxK){
                vector<int> goodArray;
                j = i;
                while(j<n && nums[j] >= minK && nums[j] <= maxK){
                    goodArray.push_back(nums[j]);
                    j++;
                }
                i = j;
                
                cnt += countSubarraysInGoodArray(goodArray,minK,maxK);
            }
            else{
                i++;
            }
        }
        
        return cnt;
    }
};