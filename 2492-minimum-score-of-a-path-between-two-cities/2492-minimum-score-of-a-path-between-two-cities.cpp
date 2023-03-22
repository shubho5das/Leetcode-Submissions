#define inf 1000000000

class Solution {
public:
    void dfs(int src,vector<bool> &visited, vector<vector<int>> &adjList){
        visited[src] = true;
        
        for(auto nbr : adjList[src]){            
            if(!visited[nbr]){
                dfs(nbr,visited,adjList);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        int i,u,v,wt,minScore;
        
        vector<vector<int>> adjList(n+1);
        for(i=0 ; i<roads.size() ; i++){
            u = roads[i][0], v = roads[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        // 1
        vector<bool> visited(n+1,false);
        dfs(1,visited,adjList);
           
        // 2
        minScore = inf;
        for(i=0 ; i<roads.size() ; i++){
            u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            if(visited[u] && visited[v]){
                minScore = min(minScore,wt);
            }
        }
        
        return minScore;     
    }
};