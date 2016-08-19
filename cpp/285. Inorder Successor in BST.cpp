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
lgn
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




stack:不取
public class Solution {
 public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
 Stack<TreeNode> stk = new Stack<TreeNode>();
 TreeNode curr = root;
 // 找到目标节点并把路径上的节点压入栈
 while(curr != p){
stk.push(curr);
 if(curr.val > p.val){
 curr = curr.left;
 } else {
 curr = curr.right;
}
}
 // 如果目标节点有右节点，则找到其右节点的最左边的节点，就是下一个数
 if(curr.right != null){
 curr = curr.right;
 while(curr.left != null){
 curr = curr.left;
}
 return curr;
 } else {
 // 如果没有右节点，pop栈找到第一个比目标节点大的节点
 while(!stk.isEmpty() && stk.peek().val < curr.val){
stk.pop();
}
 // 如果栈都pop空了还没有比目标节点大的，说明没有更大的了
 return stk.isEmpty() ? null : stk.pop();
}
}
}