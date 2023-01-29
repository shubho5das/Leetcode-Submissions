class Solution {
public:
    long long putMarbles(vector<int>& weights, long long k) {
        long long i,n,minCost,maxCost;
        n = weights.size();
        
        priority_queue<long long> maxHeap;
        priority_queue<long long,vector<long long>,greater<long long>> minHeap;                
        for(i=0 ; i<=(n-2) ; i++){
            maxHeap.push(weights[i] + weights[i+1]);
            minHeap.push(weights[i] + weights[i+1]);
        }
        
        
        minCost = weights[0], maxCost = weights[0];
        k -= 1;
        while(k--){
            // (k-1) partitions
            minCost += minHeap.top();
            minHeap.pop();
            
            maxCost += maxHeap.top();
            maxHeap.pop();
        }
        minCost += weights[n-1], maxCost += weights[n-1];
        
        return (maxCost - minCost);        
    }
};