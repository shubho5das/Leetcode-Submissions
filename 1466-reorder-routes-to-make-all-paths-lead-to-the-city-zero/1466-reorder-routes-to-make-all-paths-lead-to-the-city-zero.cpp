// Srishti's Code

class Solution {
public:
    void dfs(int v, vector<pair<int, int>> graph[], vector<bool> &vis, int &ans) {
        vis[v] = true;
        for(auto u: graph[v]) {
            if(!vis[u.first]) {
                dfs(u.first, graph, vis, ans);
                if(u.second == 1){
                     ans ++;
                     //cout<<u.first<<" "<<v<<"\n";
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> graph[n];
        for(auto u: connections) {
            graph[u[0]].push_back({u[1], 1});
            graph[u[1]].push_back({u[0], 0});
        } 
        vector<bool> vis(n, false);
        int ans = 0;
        dfs(0, graph, vis, ans);
        return ans;
    }
};