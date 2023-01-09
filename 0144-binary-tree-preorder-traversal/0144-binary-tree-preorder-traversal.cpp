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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        int i;
        vector<int> solution;
        
        if(root == NULL){
            return solution;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        while(st.size() >= 1){
            TreeNode *f = st.top();
            solution.push_back(f->val);
            st.pop();
            
            if(f->right != NULL){
                st.push(f->right);
            }
            if(f->left != NULL){
                st.push(f->left);
            }
        }
        
        return solution;
    }
};