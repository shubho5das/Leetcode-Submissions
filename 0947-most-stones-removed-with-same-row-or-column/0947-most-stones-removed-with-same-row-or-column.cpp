class Solution {
public:
    
    void dfs(int src,vector<bool> &visited,vector<vector<int>> &adjList,int &len){
        visited[src] = true;
        len++;
        
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                dfs(nbr,visited,adjList,len);
            }
        }    
    }

    int removeStones(vector<vector<int>>& stones) {
        int n,i,j,xi,yi,xj,yj,len,cnt;
        n = stones.size();
        
        // 1        
        vector<vector<int>> adjList(n);
        for(i=0 ; i<n ; i++){
            for(j=(i+1) ; j<n ; j++){
                xi = stones[i][0], yi = stones[i][1];
                xj = stones[j][0], yj = stones[j][1];
                
                if(xi == xj || yi == yj){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                } 
            }
        }
                        
        // 2
        vector<bool> visited(n+1,false);
            
        cnt = 0;        
        for(i=0 ; i<n ; i++){            
            if(!visited[i]){
                len = 0; // len of CC
                dfs(i,visited,adjList,len);
                cnt += (len - 1);
            }            
        }
        
        return cnt;                  
    }
};