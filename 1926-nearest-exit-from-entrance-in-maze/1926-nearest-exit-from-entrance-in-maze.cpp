#define inf 1000000000

class Solution {
public:
    
    void bfs_sssp(vector<vector<char>> &maze,int src_i,int src_j,vector<vector<int>> &dist){
        int i,j,m,n;
        m = maze.size();
        n = maze[0].size();
        
        queue<vector<int>> Q;
        
        Q.push({src_i,src_j});
        dist[src_i][src_j] = 0;
        while(Q.size() >= 1){
            i = (Q.front())[0];
            j = (Q.front())[1];
            Q.pop();
            
            // Up
            if( (i - 1) >= 0 && maze[i-1][j] == '.' && dist[i-1][j] == inf){
                Q.push({i-1,j});
                dist[i-1][j] = dist[i][j] + 1;
            }            
            // Down
            if((i+1) < m && maze[i+1][j] == '.' && dist[i+1][j] == inf){
                Q.push({i+1,j});
                dist[i+1][j] = dist[i][j] + 1;
            }            
            // Left
            if((j-1) >= 0 && maze[i][j-1] == '.' && dist[i][j-1] == inf){
                Q.push({i,j-1});
                dist[i][j-1] = dist[i][j] + 1;
            }
            // Right
            if((j+1) < n && maze[i][j+1] == '.' && dist[i][j+1] == inf){
                Q.push({i,j+1});
                dist[i][j+1] = (dist[i][j] + 1);
            }            
        }                
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int> &entrance){
        int m,n,i,j,src_i,src_j,ans;
        m = maze.size(), n = maze[0].size();
        
        src_i = entrance[0], src_j = entrance[1];
        
        // 1
        vector<vector<int>> dist(m,vector<int>(n,inf));
        bfs_sssp(maze,src_i,src_j,dist);
        
        // 2
        ans = inf;
        for(i=0 ; i<m ; i++){
            for(j=0 ; j<n ; j++){
                if(maze[i][j] == '.' && !(i==src_i && j == src_j) && (i == 0 || i == (m-1) || j == 0 || j == (n-1)) ){
                    ans = min(ans,dist[i][j]);
                }
            }
        }
                        
        return (ans == inf)? -1 : ans;            
    }
};