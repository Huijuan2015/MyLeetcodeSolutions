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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
private:
    void traverse(TreeNode* root, vector<int>& result){
        /*if(root == NULL){
            return;
        }   
        
        traverse(root->left, result);
        result.push_back(root->val);
        traverse(root->right, result);
    }*/
        
        
        
        
        
        /*
        vector<int> result;
        TreeNode* p = root;
        stack<TreeNode*> s;
        
        while(!s.empty() || p != nullptr){
            if(p != nullptr){
                s.push(p);
                p=p->left;
            }else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p=p->right;
            }
        }
        return result;
    }*/
};