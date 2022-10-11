class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2){
        int n1,n2,i,j,ans;
        n1 = nums1.size();
        n2 = nums2.size();
            
        ans = 0;
        for(i=0 ; i<n1 ; i++){
            if(n2%2 == 1){
                ans ^= nums1[i];
            }
        }
        for(i=0 ; i<n2 ; i++){
            if(n1%2 == 1){
                ans ^= nums2[i];
            }
        }
        
        return ans;
    }
};