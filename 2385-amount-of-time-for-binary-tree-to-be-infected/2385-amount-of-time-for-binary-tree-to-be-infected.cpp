/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define inf 1000000000

class Solution {
public:
    
    void dfs(TreeNode* root,map<int,vector<int>> &adjList){
        int currentNode, nbrNode;
        
        if(root == NULL){
            return;
        }
        
        currentNode = root->val;
        // cout<<currentNode<<"\n";
        
        if(root->left != NULL){
            nbrNode = (root->left)->val;
            adjList[currentNode].push_back(nbrNode);
            adjList[nbrNode].push_back(currentNode);
            dfs(root->left,adjList);
        }
        
        if(root->right != NULL){
            nbrNode = (root->right)->val;
            adjList[currentNode].push_back(nbrNode);
            adjList[nbrNode].push_back(currentNode);
            dfs(root->right,adjList);
        }                        
    }
    
    void bfs(int src,map<int,vector<int>> &adjList,map<int,int> &dist){
        int currentNode;
        
        queue<int> Q;
        
        Q.push(src);
        dist[src] = 0;
        while(Q.size() >= 1){
            currentNode = Q.front();
            Q.pop();
            
            for(auto nbr : adjList[currentNode]){
                if(dist[nbr] == inf){
                    Q.push(nbr);
                    dist[nbr] = (dist[currentNode] + 1);
                }
            }
        }                
    }
    
    int amountOfTime(TreeNode* root, int src) {
        int maxDist;
        
        
        // 1
        map<int,vector<int>> adjList;
        dfs(root,adjList);
        
        
        // 2
        map<int,int> dist;
        for(auto x : adjList){
            dist[x.first] = inf;
        }
        
        bfs(src,adjList,dist);
                
        // 3
        maxDist = -inf;
        for(auto x : dist){
            // cout<<x.first<<" "<<x.second<<"\n";
            maxDist = max(maxDist,x.second);
        }
        
        return maxDist;
    }
};