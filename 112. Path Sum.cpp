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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) return sum == root->val;
        else{
            return hasPathSum(root->right, sum-root->val) || hasPathSum(root->left, sum-root->val);
        }
    }
    
   
};


有意思的BFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        stack<pair<TreeNode*, int> > pairs;
        pairs.push(make_pair(root, sum));
        while (!pairs.empty()) {
            pair<TreeNode*, int> pr = pairs.top();
            pairs.pop();
            TreeNode* node = pr.first;
            int remain = pr.second;
            if (!(node -> left) && !(node -> right) && remain == node -> val)
                return true;
            if (node -> left)
                pairs.push(make_pair(node -> left, remain - node -> val));
            if (node -> right)
                pairs.push(make_pair(node -> right, remain - node -> val));
        }
        return false;
    }
};