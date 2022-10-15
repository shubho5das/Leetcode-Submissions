#define inf 1000000000

class Solution {
public:
    int findMaximumElement(vector<vector<int>> &grid,int pos_i,int pos_j){
        int mx,i,j;
        
        mx = -inf;
        for(i=(pos_i-1) ; i<=(pos_i+1) ; i++){
            for(j=(pos_j-1) ; j<=(pos_j+1) ; j++){
                mx = max(grid[i][j],mx);
            }
        }
        
        return mx;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>> &grid){
        int i,j,n,mx;
        n = grid.size();
        
        vector<vector<int>> solution;
        for(i=1 ; i<=(n-2) ; i++){
            vector<int> current;
            for(j=1 ; j<=(n-2) ; j++){
                mx = findMaximumElement(grid,i,j);
                current.push_back(mx);
            }                
            solution.push_back(current);
        }
        
        return solution;
    }
};