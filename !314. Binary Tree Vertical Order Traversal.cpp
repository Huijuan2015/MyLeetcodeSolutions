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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector< vector<int> > res;
        if(!root) return res;
        
        queue <pair<TreeNode*, int>> q;//node and dist
        //用map排序  从小到大输出
        map<int, vector<int> > cols;//dist and nodes
        q.emplace(root,0);
        
        while(!q.empty()){
            auto node = q.front().first;
            int dist = q.front().second;
            q.pop();
            cols[dist].push_back(node->val);
            if(node->left) q.emplace(node->left, dist-1);
            if(node->right) q.emplace(node->right, dist+1);
        }
        
        for(auto col : cols){
            res.push_back(col.second);
        }
        
        return res;
    }
};