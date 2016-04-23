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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //bfs
        vector< vector<int> > res;
        if(!root) return res;
        
        queue<TreeNode*> level;
        level.push(root);
        int levelSize = 1;
        while(!level.empty()){
            vector<int> curLevel;
            for(int i = 0; i < levelSize; ++i){
                TreeNode * tmp = level.front();
                curLevel.push_back(tmp->val);
                level.pop();
                if(tmp->left)level.push(tmp->left);
                if(tmp->right)level.push(tmp->right);
            }
            res.push_back(curLevel);
            levelSize = level.size();//level.size()是不停变化的，所以要为下一轮一个固定值
        }
        return res;
    }
};