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
    
    static const long long inf = 1e18;
    
    int widthOfBinaryTree(TreeNode* root){
        long long mn_idx,leftmostIndex,rightmostIndex,currentWidth,maxWidth,idx,len;
        
        queue<pair<TreeNode*,long long>> Q; // {node*,idx}
        Q.push({root,0LL});
        
        maxWidth = 0;
        while(Q.size() >= 1){
            len = Q.size();
            mn_idx = Q.front().second;
            
            leftmostIndex = inf,rightmostIndex = -inf;
            while(len--){
                TreeNode *f = Q.front().first;
                idx = Q.front().second;
                Q.pop();
                
                leftmostIndex = min(leftmostIndex,idx);
                rightmostIndex = max(rightmostIndex,idx);
                
                idx -= mn_idx; // To avoid overflow (while giving indices to child nodes)
                if(f->left != NULL){
                    Q.push({f->left,2*idx});
                }
                if(f->right != NULL){
                    Q.push({f->right,(2*idx + 1)});
                }
            }
            
            currentWidth = (rightmostIndex - leftmostIndex + 1);
            maxWidth = max(maxWidth,currentWidth);
        }
        
        return maxWidth;
    }
};