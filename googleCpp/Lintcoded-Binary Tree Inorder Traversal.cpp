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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        
        vector<int> left, right;
        left = inorderTraversal(root->left);
        right = inorderTraversal(root->right);
        res = left;
        res.push_back(root->val);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};




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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;

        TreeNode* cur = root;
        
        while(cur || !stk.empty()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};



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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        Helper(root);
        return res;
    }
    
    void Helper(TreeNode* root){
        if(!root) return;
        Helper(root->left);
        res.push_back(root->val);
        Helper(root->right);
    }
};