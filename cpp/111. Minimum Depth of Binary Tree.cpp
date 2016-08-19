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
    int minDepth(TreeNode* root) {
        //dfs
        if(!root) return 0;
        //depth 停在左右子节点都为空的节点
        //different from maximum depth. if a node only has one child, the depth will be 1 + child depth.
        if(!root->right) return minDepth(root->left)+1;
        if(!root->left) return minDepth(root->right)+1;
        return min(minDepth(root->right), minDepth(root->left))+1;
    }
};




**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        int curr_depth=0,min_depth=1000000;
        return PreorderTraverse(root,&curr_depth,min_depth);
    }
 
private:
    int PreorderTraverse(TreeNode *root, int *curr_depth, int min_depth){
        if(root==nullptr)return 0;
         
        (*curr_depth)++;
        if(root->left!=nullptr){
            min_depth=PreorderTraverse(root->left, curr_depth, min_depth);
        }
        if(root->right!=nullptr){
            min_depth=PreorderTraverse(root->right, curr_depth, min_depth);
        }
        if((root->left==nullptr)&&(root->right==nullptr)){
            min_depth=min(*curr_depth,min_depth);
        }
         
        (*curr_depth)--;
        return min_depth;
    }
};