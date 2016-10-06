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
     * @return: Preorder in vector which contains node values.
     */
      vector<int> res;
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
       
        Helper(root);
        return res;
        //return res;
    }
    void Helper(TreeNode* root){
        if(!root) return ;
        res.push_back(root->val);
        Helper(root->left);
        Helper(root->right);
    }
};


---------------

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
     * @return: Preorder in vector which contains node values.
     */
      
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
       vector<int> left;
       vector<int> right;
        res.push_back(root->val);
        left = preorderTraversal(root->left);
        right = preorderTraversal(root->right);
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(),right.begin(),right.end());
        return res;

    }

};

-----------------
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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode*> stk;
        vector<int> res;
        if(!root) return res;
        
        stk.push(root);
        
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            res.push_back(tmp->val);
            stk.pop();
            if(tmp->right)stk.push(tmp->right);
            if(tmp->left)stk.push(tmp->left);
            
        }
        return res;
    }
};
