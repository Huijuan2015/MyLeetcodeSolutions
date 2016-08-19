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
    bool isSymmetric(TreeNode* root) {
        //DFS
        /*if(!root) return true;
        return isSymHelper(root->right, root->left);
    }
    
    bool isSymHelper(TreeNode* right, TreeNode* left){
        if(!right && !left) return true;
        if(!right || !left) return false;
        if(right->val != left->val) return false;
        else{
            return isSymHelper(right->left, left->right) && isSymHelper(right->right, left->left);
        }
        
    }*/
    
    
    //BFS
       if(!root) return true;
       stack<TreeNode*> leftStk;
       stack<TreeNode*> rightStk;
       
       leftStk.push(root->left);
       rightStk.push(root->right);
       
       while(!leftStk.empty() && !rightStk.empty()){
           TreeNode* left = leftStk.top();
           TreeNode* right = rightStk.top();
           //注意何时pop
           leftStk.pop();
           rightStk.pop();
           
           if(!left && !right) continue;
           if(!left || !right) return false;
           
           if(left->val != right->val) return false;
           else{
               leftStk.push(left->left);
               leftStk.push(left->right);
               rightStk.push(right->right);
               rightStk.push(right->left);
           }
       }
       return true;
    }
       

};