/*--------------- pbds - ordered_multiset ---------------*/
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
/*-------------------------------------------------------*/


class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int d){
        long long n,i,currentCnt,totalCnt,key,idx;
        n = nums1.size();
        
        // 1
        vector<int> diff(n);
        for(i=0 ; i<n ; i++){
            diff[i] = (nums1[i] - nums2[i]);        
        }
        
        // 2
        ordered_multiset P;        
        totalCnt = 0;
        for(i=(n-1) ; i>=0 ; i--){
            key = (diff[i] - d);
            idx = P.order_of_key(key);
            currentCnt = (P.size() - idx);
            
            totalCnt += currentCnt;
            
            P.insert(diff[i]);
        }
        
        return totalCnt;        
    }
};