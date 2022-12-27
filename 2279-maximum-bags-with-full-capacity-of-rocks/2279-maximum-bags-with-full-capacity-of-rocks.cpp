class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n,i,cnt,toFill;
        n = capacity.size();
        
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(i=0 ; i<n ; i++){
            minHeap.push(capacity[i] - rocks[i]);
        }
                
        cnt = 0;
        while(additionalRocks >= 1 && minHeap.size() >= 1){
            toFill = minHeap.top();
            minHeap.pop();
            
            if(additionalRocks >= toFill){
                additionalRocks -= toFill;
                cnt++;
            }
            else{
                break;
            }            
        }
        
        return cnt;                            
    }
};