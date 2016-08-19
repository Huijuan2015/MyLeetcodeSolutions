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
    int maxDepth(TreeNode* root) {
       //DFS
        //return root ? 1+max(maxDepth(root->left), maxDepth(root->right)) :0; 
        //bfs queue
        
        int depth = 0;
        if(!root) return depth;
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()){
            depth ++;
            int n = level.size();
            for(int i = 0; i < n; ++i){
                TreeNode* tmp = level.front();
                level.pop();
                if(tmp->left) level.push(tmp->left);
                if(tmp->right) level.push(tmp->right);
            }
        }
        return depth;
    }
};