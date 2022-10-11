#define inf 1000000000

class Solution {
public:
    
    void bfs(int src,vector<int> &dist,vector<vector<int>> &adjList){
        int currentNode;
        
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;
        while(Q.size() >=  1){
            currentNode = Q.front();
            Q.pop();
            
            for(auto nbr : adjList[currentNode]){
                if(dist[nbr] == inf){
                    Q.push(nbr);
                    dist[nbr] = dist[currentNode] + 1;
                }
            }
        }        
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int u,v,n,i,current,mn,idx;
        n = edges.size();
        
        vector<vector<int>> adjList(n);
        for(i=0 ; i<n ; i++){
            u = i, v = edges[i];
            if(v != -1){
                adjList[u].push_back(v);
            }
        }        
        
        // 1
        vector<int> dist1(n,inf);
        bfs(node1,dist1,adjList);
            
        vector<int> dist2(n,inf);
        bfs(node2,dist2,adjList);
            
        // 2
        mn = inf, idx = -1;
        for(i=0 ; i<n ; i++){
            if((dist1[i] != inf) && (dist2[i] != inf)){
                current = max(dist1[i],dist2[i]);
                if(current < mn){
                    mn = current;
                    idx = i;
                }
            }
        }
        
        return idx;
    }
};