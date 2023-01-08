class Solution {
public:
    long long ceil(long long a,long long b){    
        return((a+b-1)/b);
    }    
    
    long long maxKelements(vector<int>& nums, int k) {
        long long n,i,ans,chosenValue;
        n = nums.size();
        
        priority_queue<long long> maxHeap(nums.begin(),nums.end());
        
        ans = 0;
        while(k--){
            chosenValue = maxHeap.top();
            maxHeap.pop();
            
            ans += chosenValue;
            
            chosenValue = ceil(chosenValue,3);            
            maxHeap.push(chosenValue);
        }
        
        return ans;        
    }
};