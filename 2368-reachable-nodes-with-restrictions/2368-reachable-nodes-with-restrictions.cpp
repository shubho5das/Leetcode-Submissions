class Solution {
public:
    
    void dfs(int src,vector<bool> &visited,vector<vector<int>> &adjList,vector<bool>& isRestricted,int &cnt){
        if(isRestricted[src]){
            return;
        }
        
        visited[src] = true;
        cnt++;
        
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                dfs(nbr,visited,adjList,isRestricted,cnt);
            }
        }        
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int i,u,v,cnt;
                
        vector<vector<int>> adjList(n);
        for(i=0 ; i<edges.size(); i++){
            u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool> visited(n,false);
        
        vector<bool> isRestricted(n,false);
        for(i=0 ; i<restricted.size() ; i++){
            isRestricted[restricted[i]] = true;
        }
                        
        cnt = 0;
        dfs(0,visited,adjList,isRestricted,cnt);
        
        return cnt;        
    }
};