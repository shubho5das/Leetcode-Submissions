#define inf 1000000000

class Solution {
public:
    void dfs(int src,vector<bool> &visited, vector<vector<vector<int>>> &adjList,int &minEdge){
        visited[src] = true;
        
        for(auto nbr : adjList[src]){ 
            int nbrNode = nbr[0];
            int nbrWt = nbr[1];
            
            minEdge = min(minEdge, nbrWt); // Considering all the edges connected to the currentNode (In this way, all the edges of the CC are covered) 
            
            if(!visited[nbrNode]){                
                dfs(nbrNode,visited,adjList,minEdge);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        int i,u,v,wt,minEdge;
        
        vector<vector<vector<int>>> adjList(n+1);
        for(i=0 ; i<roads.size() ; i++){
            u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            adjList[u].push_back({v,wt});    
            adjList[v].push_back({u,wt});    
        }
       
        vector<bool> visited(n+1,false);
        minEdge = inf;
        dfs(1,visited,adjList,minEdge);
        
        return minEdge;
    }
};