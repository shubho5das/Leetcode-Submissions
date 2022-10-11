class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n,i,s,e,mid,ans;      
        n = arr.size();
        
        s = 1, e = (n-2);
        while(s <= e){
            mid = s + (e-s)/2;            
            if(arr[mid] > arr[mid-1]){
                ans = mid;
                s = (mid + 1);
            }
            else{
                e = (mid - 1);
            }
        }
        
        return ans;
    }
};