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
     * @return: True if the binary tree is BST, or false
     */
     TreeNode* pre = NULL;
    bool isValidBST(TreeNode *root) {
        // write your code here
        if(root){
            if(!isValidBST(root->left)) return false;
            
            if(pre && root->val <= pre->val ) return false;
            
            pre = root;
            return isValidBST(root->right);
        }
        return true;
        
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
     TreeNode* pre = NULL;
    bool isValidBST(TreeNode *root) {
        // write your code here
        if(!root)
            return true;
        if(root->left)
        {
          TreeNode *p=root->left;
          while(p->right)
            p=p->right;
          if(p->val>=root->val)
            return false;//左子树最右边的孩子比根小
        }
        if(root->right)
        {
          TreeNode *p=root->right;
          while(p->left)
            p=p->left;
          if(p->val<=root->val)
            return false;//右子树最左边的孩子比根大
        }
        
        return isValidBST(root->left)&&isValidBST(root->right);
        
    }
};











