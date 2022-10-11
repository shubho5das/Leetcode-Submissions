class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int i,j,n;
        n = nums.size();
        
        // 1.0
        vector<int> increasingIndex;
        vector<int> decreasingIndex;
        for(i=0 ; i<=(n-2) ; i++){
            if(nums[i] < nums[i+1]){
                increasingIndex.push_back(i);  // Strictly increasing
            }
            if(nums[i] > nums[i+1]){
                decreasingIndex.push_back(i);  // Strictly decreasing
            }
        }
        
        // 1.1
        vector<bool> isDecreasing(n,false);  // Segment [i,i+k-1] decreasing?
        j = 0;
        for(i=0 ; i<=(n-k) ; i++){
            while(j < increasingIndex.size() && increasingIndex.size() >= 1 && increasingIndex[j] < i){
                j++;
            }
            
            if( (increasingIndex.size() >= 1) && (j < increasingIndex.size()) && (increasingIndex[j] >= i && increasingIndex[j] <= (i+k-2)) ){
                isDecreasing[i] = false;    
            }
            else{
                isDecreasing[i] = true;                        
            }             
        }
                        
        // 1.2
        vector<bool> isIncreasing(n,false);
        j = 0;
        for(i=0 ; i<=(n-k) ; i++){
            while(j < decreasingIndex.size() && decreasingIndex.size() >= 1 && decreasingIndex[j] < i){
                j++;
            }
            
            if( (decreasingIndex.size() >= 1) && (j < decreasingIndex.size()) && (decreasingIndex[j] >= i && decreasingIndex[j] <= (i+k-2)) ){
                isIncreasing[i] = false;    
            }
            else{
                isIncreasing[i] = true;                        
            }                                                     
        }
        
        // 2
        vector<int> solution;     
        for(i=k ; i<=(n - k - 1) ; i++){            
            if(isDecreasing[i-k] && isIncreasing[i+1]){
                solution.push_back(i);
            }                                
        }
        
        return solution;
    }
};