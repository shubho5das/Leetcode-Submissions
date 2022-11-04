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
     void dfs(TreeNode *root,int targetValue,TreeNode* &targetNodeInCloned){
        // Base Case
        if(root == NULL){
            return;            
        }
         
        if(root->val == targetValue){
            targetNodeInCloned = root;
            return;
        }         
         
        // General Case
        dfs(root->left,targetValue,targetNodeInCloned);                 
        dfs(root->right,targetValue,targetNodeInCloned);                  
     }
        
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int targetValue;
        
        // 1
        targetValue = (target->val);
         
        // 2
        TreeNode* targetNodeInCloned = NULL;
        dfs(cloned,targetValue,targetNodeInCloned);
        
        return targetNodeInCloned;
    }
};