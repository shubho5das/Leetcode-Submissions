class Solution {
public:
    void countPaths(vector<vector<int>> &grid,int m,int n,int i,int j,vector<vector<bool>> &visited, int &cnt,int &cntZeroes,int totalZeroes){
        // Base Case
        if(grid[i][j] == 2){
            if(cntZeroes == totalZeroes){
                cnt++;
            }
            return;
        }
        
        // General Case
        if(grid[i][j] == 0){
            cntZeroes++;
        }
        visited[i][j] = true;
        
        
        // Up
        if((i-1) >= 0 && grid[i-1][j] != -1 && !visited[i-1][j]){
            countPaths(grid,m,n,i-1,j,visited,cnt,cntZeroes,totalZeroes);
        }
        
        //Down
        if((i+1) < m && grid[i+1][j] != -1 && !visited[i+1][j]){
            countPaths(grid,m,n,i+1,j,visited,cnt,cntZeroes,totalZeroes);
        }
        
        
        // Left
        if((j-1) >= 0 && grid[i][j-1] != -1 && !visited[i][j-1]){
            countPaths(grid,m,n,i,j-1,visited,cnt,cntZeroes,totalZeroes);
        }
        
        // Right
        if((j+1) < n && grid[i][j+1] != -1 && !visited[i][j+1]){
            countPaths(grid,m,n,i,j+1,visited,cnt,cntZeroes,totalZeroes);
        }
        
        if(grid[i][j] == 0){
            cntZeroes--;
        }
        visited[i][j] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m,n,i,j,src_i,src_j,cntZeroes,totalZeroes,cnt;
        m = grid.size();
        n = grid[0].size();
        
        totalZeroes = 0;
        src_i = -1,src_j = -1;
        for(i=0 ; i<m ; i++){
            for(j=0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    totalZeroes++;
                }
                
                if(grid[i][j] == 1){
                    src_i= i, src_j = j;
                }
            }
        }
                
        cnt = 0,cntZeroes = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));        
        countPaths(grid,m,n,src_i,src_j,visited,cnt,cntZeroes,totalZeroes);        
        return cnt;
    }
};