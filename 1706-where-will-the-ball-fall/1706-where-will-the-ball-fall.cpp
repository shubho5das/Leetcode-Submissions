class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m,n,i,row,col;
        m = grid.size(), n = grid[0].size();
        
        vector<int> solution(n);
        for(i=0 ; i<n ; i++){            
            bool ballStuck = false;            
            row = 0, col = i;
            for( ; row<m ; row++){
                if(grid[row][col] == 1){
                    if(col <= (n-2) && grid[row][col+1] == 1){
                        col++;
                    }
                    else{
                        ballStuck = true;
                        break;
                    }
                }
                else{
                    if(col >= 1 && grid[row][col-1] == -1){
                        col--;
                    }
                    else{
                        ballStuck = true;
                        break;
                    }
                }
            }
            
            solution[i] = (ballStuck)? -1 : col;            
        }
        
        return solution;
    }
};