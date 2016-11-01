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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
     
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        inorder_dfs(res, root, k1, k2);

        return res;
    }
    
    void inorder_dfs(vector<int>& ret,TreeNode* root, int k1, int k2){
        if (NULL == root) {
            return;
        }

        if ((root->left) && (root->val > k1)) {
            inorder_dfs(ret, root->left, k1, k2);
        } // cut-off for left sub tree

        if ((root->val >= k1) && (root->val <= k2)) {
            ret.push_back(root->val);
        } // add valid value

        if ((root->right) && (root->val < k2)) {
            inorder_dfs(ret, root->right, k1, k2);
        } // cut-off for right sub tree
    }
};