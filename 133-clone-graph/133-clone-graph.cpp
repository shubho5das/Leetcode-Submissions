/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:    
    unordered_map<Node*,Node*> copy;

    Node* cloneGraph(Node* src){
        // Simple dfs traversal (recursion)
        
        // Base Case
        if(src == NULL){
            return NULL;
        }
        
        // General Case
        if(copy.find(src) == copy.end()){
            // Copy of src not yet created
            copy[src] = new Node(src->val,{});
            
            for(Node* nbr : src->neighbors){
                (copy[src]->neighbors).push_back(cloneGraph(nbr));             
            }
        }
        
        return copy[src];        
    }
};