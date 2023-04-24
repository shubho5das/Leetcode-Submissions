// Solved previolsy
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n,i,x,y,smashedStone;
        n = stones.size();
        
        priority_queue<int> maxHeap;        
        for(i=0 ; i<n ; i++){
            maxHeap.push(stones[i]);
        }
        
        while(maxHeap.size() >= 2){
            x = maxHeap.top();
            maxHeap.pop();
            
            y = maxHeap.top();
            maxHeap.pop();
            
            smashedStone = abs(x - y);
            if(smashedStone > 0){
                maxHeap.push(smashedStone);
            }            
        }
        
        return (maxHeap.size() == 0)? 0 : maxHeap.top();
    }
};