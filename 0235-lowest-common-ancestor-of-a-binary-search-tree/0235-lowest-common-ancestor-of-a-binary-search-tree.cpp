/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case
        if(p->val == root->val){
            return p;
        } 
    
        if(q->val == root->val){
            return q;
        }
        
        if( (p->val < root->val) && (q->val > root->val) ){
            return root; 
        }
    
        // General Case
        if( (p->val < root->val) && (q->val < root->val) ){
            return findLCA(root->left,p,q); 
        }
        else{
            return findLCA(root->right,p,q); 
        }
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            swap(p,q);
        }
        
        return findLCA(root,p,q);        
    }
};
