/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(!root) return true;
        
        return depth(root) != -1;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        //int maxDepth;
        int left = depth(root->left);
        int right= depth(root->right);
        if(left == -1 || right == -1 || abs(left-right)>1){
            return -1;
        }
        return max(right, left)+1;
        }
};