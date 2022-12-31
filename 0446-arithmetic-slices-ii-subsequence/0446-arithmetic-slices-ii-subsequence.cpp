class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long n,i,j,commonDiff,ans;
        n = nums.size();
                                        
        unordered_map<long long,long long> M[n]; // M[i]: {commonDiff,cnt of AP's len >= 2 ending with nums[i]} 
        
        ans = 0;
        for(i=0 ; i<n ; i++){
            for(j=0 ; j<=(i-1) ; j++){
                commonDiff = (long long)(nums[i]) - (long long)(nums[j]);
                if(M[j].find(commonDiff) != M[j].end()){
                    ans += M[j][commonDiff];
                    M[i][commonDiff] += (M[j][commonDiff] + 1);
                }
                else{
                    M[i][commonDiff] += 1;
                }
            }
        }
        
        return ans;
    }
};