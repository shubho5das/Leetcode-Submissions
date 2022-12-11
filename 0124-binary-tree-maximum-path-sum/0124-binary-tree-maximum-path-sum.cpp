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
    
    static const int inf  = 1e9;
    
    static int findMaxSum(TreeNode* root, int &overallMaxSum){
        int op1,op2,op3,op4,leftSum,rightSum,currentMaxSum;
        
        // Base Case
        if(root == NULL){
            return 0;
        }
        
        // General Case
        leftSum = findMaxSum(root->left,overallMaxSum);
        rightSum = findMaxSum(root->right,overallMaxSum);
        
        op1 = (root->val);
        op2 = (root->val) + leftSum;
        op3 = (root->val) + rightSum;
        op4 = (root->val) + leftSum + rightSum;
        
        currentMaxSum = max({op1,op2,op3,op4}); // Max sum passing through the current root
        overallMaxSum = max(overallMaxSum,currentMaxSum); // Overall max sum
        return (max({op1,op2,op3}));   // Max Sum, with branch starting from root (op4 cannot be considered here, since it cannot be extended)
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum,sum;
        
        maxSum = -inf;
        sum = findMaxSum(root,maxSum);
        return maxSum;
    }
};