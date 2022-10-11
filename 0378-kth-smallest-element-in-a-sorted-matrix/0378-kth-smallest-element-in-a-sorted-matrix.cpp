class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n,i,j;
        n = matrix.size();
        
        priority_queue<int> maxHeap;
        for(i=0 ; i<n ; i++){
            for(j=0 ; j<n ; j++){
                if(maxHeap.size() < k){
                    maxHeap.push(matrix[i][j]);
                }
                else{
                    if(maxHeap.top() > matrix[i][j]){
                        maxHeap.pop();
                        maxHeap.push(matrix[i][j]);
                    }
                }
            }
        }
        
        return maxHeap.top();        
    }
};