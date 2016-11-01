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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res, left,right;
        if(!root) return res;
        left = postorderTraversal(root->left);
        right = postorderTraversal(root->right);
        res = left;
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        
        while(!stk.empty()){
          curr = stk.top();
          //如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被
        //访问输出,则直接输出该节点，将其出栈，将其设为上一个访问的节点
          if((!curr->right&&!curr->left) || (prev &&(curr->right==prev || curr->left == prev))){
              res.push_back(curr->val);
              stk.pop();
              prev = curr;
          }else{ //如果不满足上面两种情况,则将其右孩子左孩子依次入栈 
              if(curr->right) stk.push(curr->right);
              if(curr->left)stk.push(curr->left);
          }
          
        }
        return res;
    }
};