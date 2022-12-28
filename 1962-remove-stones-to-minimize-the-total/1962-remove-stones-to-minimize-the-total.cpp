class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n,i,current,ans;
        n = piles.size();
        
        priority_queue<int> maxHeap;
        for(i=0 ; i<n ; i++){
            maxHeap.push(piles[i]);
        }
        
        while(k--){
            current = maxHeap.top();
            maxHeap.pop();
            
            current -= current/2;
            
            maxHeap.push(current);
        }
        
        ans = 0;
        while(maxHeap.size() >= 1){
            ans += maxHeap.top();
            maxHeap.pop();
        }
        
        return ans;
    }
};