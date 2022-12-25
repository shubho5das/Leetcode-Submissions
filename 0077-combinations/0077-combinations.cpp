class Solution {
public:
    void findCombinations(vector<int> nums,int n,int i,int k,vector<int> &current,vector<vector<int>> &solution){
        int j;
        
        // Base Case
        if(current.size() == k){
            return;
        }
        
        // General Case
        current.push_back(nums[i]);
        if(current.size() == k){
            solution.push_back(current);
        }        
        
        for(j=(i+1) ; j<n ; j++){
            findCombinations(nums,n,j,k,current,solution);
        }
        
        current.pop_back(); 
    }
    
    vector<vector<int>> combine(int n, int k) {
        int i;
        
        vector<int> nums(n);
        for(i=0 ; i<n ; i++){
            nums[i] = (i+1);
        }
        
        vector<vector<int>> solution;
        vector<int> current;
        for(i=0 ; i<n ; i++){
            findCombinations(nums,n,i,k,current,solution);    
        }
        
        return solution;
    }
};