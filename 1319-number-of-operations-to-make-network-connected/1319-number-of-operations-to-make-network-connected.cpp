class Solution {
public:
    void dfs(int src,vector<bool> &visited,vector<vector<int>> &adjList,int &cntEdges,int &sz){
        visited[src] = true;
        cntEdges += (adjList[src].size());
        sz++;
        
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                dfs(nbr,visited,adjList,cntEdges,sz);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int i,u,v,needed,extra,cntCC,cntEdges,sz;
        
        vector<vector<int>> adjList(n);
        for(auto e : connections){
            u = e[0], v = e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool> visited(n+5,false);
        
        extra = 0;
        cntCC = 0;
        for(i=0 ; i<n ; i++){
            if(!visited[i]){
                cntEdges = 0, sz = 0;
                dfs(i,visited,adjList,cntEdges,sz);
                cntEdges /= 2;
                
                extra += (cntEdges - (sz - 1));
                cntCC++;
            }
        }
        
        needed = (cntCC - 1);
        
        return (needed <= extra)? needed : -1;                
    }
};











