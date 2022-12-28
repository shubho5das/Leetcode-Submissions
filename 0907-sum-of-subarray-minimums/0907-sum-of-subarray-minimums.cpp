#define mod 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr){
        long long n,i,l,r,mn,ans;
        n = arr.size();
        
        // Next Smaller
        stack<int> st1;   // idx, not val
        vector<int> nextSmaller(n);
        
        for(i=(n-1) ; i>=0 ; i--){
            while(st1.size() >= 1 && arr[st1.top()] > arr[i]){
                st1.pop();
            }
            
            nextSmaller[i] = (st1.size() >= 1)? st1.top() : n;
            st1.push(i);
        }
        
                                        
        // Prev Smaller  (code same as next smaller, but left-to-right)
        stack<int> st2;
        vector<int> prevSmaller(n);
        
        for(i=0 ; i<n ; i++){
            while(st2.size() >= 1 && arr[st2.top()] >= arr[i]){
                st2.pop();
            }
            
            prevSmaller[i] = (st2.size() >= 1)? st2.top() : -1;
            st2.push(i);            
        }
        
        ans = 0;
        for(i=0 ; i<n ; i++){            
            l = prevSmaller[i], r = nextSmaller[i];
            mn = arr[i];
            ans = (ans%mod  + (((i - l)%mod * (r - i)%mod)%mod * mn%mod)%mod) % mod;            
        }
        
        return ans;
    }
};