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
     * @return: An integer
     */
     int maxSum = INT_MIN;
    int maxPathSum(TreeNode *root) {
        // write your code here
        if(!root) return 0;
        maxSum = root->val;
        Helper(root);
        return maxSum;
        
    }
    int Helper(TreeNode* root){
        if(!root) return 0;
        int left = Helper(root->left);
        int right = Helper(root->right);
        int biggerBranch = max(left,right);
        
        int sum = root->val;
        sum += (left>0?left:0);
        sum += (right>0?right:0);
        maxSum = max(maxSum, sum);
        
        //return值，有三种可能，当前加左，当前加右，当前自己。
        //这里如果考虑进去了当前加左右子树，会在答案里出现末端分叉的最大路径，故不符合题目要求。想清楚这个题目就简单了
        return (biggerBranch>0? biggerBranch+root->val:root->val);
        //return sum;
    }
};
