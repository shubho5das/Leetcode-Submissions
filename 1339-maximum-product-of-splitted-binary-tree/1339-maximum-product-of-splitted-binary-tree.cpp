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
#define mod 1000000007

class Solution {
public:    
    void findTotalSum(TreeNode *root,long long &sum){
        if(root == NULL){
            return;
        }

        sum += (root->val);
        findTotalSum(root->left,sum);
        findTotalSum(root->right,sum);
    }

    long long findMaxProduct(TreeNode *root,long long totalSum,long long &maxProduct){
        long long leftSum,rightSum,currentSum,currentProduct;

        // Base Case
        if(root == NULL){
            return 0;
        }

        // General Case
        leftSum = findMaxProduct(root->left,totalSum,maxProduct);
        rightSum = findMaxProduct(root->right,totalSum,maxProduct);

        currentSum = (leftSum + rightSum + root->val);
        currentProduct = (currentSum * (totalSum - currentSum));
        maxProduct = max(currentProduct,maxProduct);

        return currentSum;
    }


    int maxProduct(TreeNode* root) {
        long long totalSum,maxProduct;

        totalSum = 0;
        findTotalSum(root,totalSum);

        maxProduct = -1;
        findMaxProduct(root,totalSum,maxProduct);

        return (maxProduct % mod);
    }
};
