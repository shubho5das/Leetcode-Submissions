class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n,i;
        n = pref.size();
        
        vector<int> arr(n);
        arr[0] = pref[0];
        for(i=1 ; i<n ; i++){
            arr[i] = (pref[i] ^ pref[i-1]);
        }
        
        return arr;
    }
};