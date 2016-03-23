/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
1.The easier one: p has right subtree, then its successor is just the leftmost child of its right subtree;
2.The harder one: p has no right subtree, then a traversal is needed to find its successor.
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right) return leftMost(p->right);
        TreeNode* suc = NULL;
        while(root){
            if(p->val < root->val){
                suc = root;
                root = root->left;
            }else if(p->val > root->val){
                root = root->right;
            }else break;
        }
        return suc;
    }
    
    TreeNode* leftMost(TreeNode* node){
        while(node->left){
            node = node->left;
        }
        return node;
    }
};