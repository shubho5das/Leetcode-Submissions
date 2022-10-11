class Solution {
public:
    
    int hourglassSum(vector<vector<int>> &grid,int current_i,int current_j){
        int sum,i,j;
        
        sum = 0;
        // 1st Row
        i = current_i;
        for(j=current_j ; j<=(current_j + 2) ; j++){
            sum += grid[i][j];
        }        
        // 2nd Row
        i = (current_i + 1);
        sum += grid[i][current_j + 1];         
        // 3rd Row
        i = (current_i + 2);
        for(j=current_j ; j<=(current_j + 2) ; j++){
            sum += grid[i][j];
        }
        
        return sum;        
    }
    
    int maxSum(vector<vector<int>>& grid) {
        int i,j,m,n,currentSum,mxSum;
        m = grid.size();
        n = grid[0].size();
        
        mxSum = 0;
        for(i=0 ; i<=(m-3) ; i++){
            for(j=0 ; j<=(n-3) ; j++){
                currentSum = hourglassSum(grid,i,j);
                mxSum = max(mxSum,currentSum);
            }
        }
        
        return mxSum;
    }
};