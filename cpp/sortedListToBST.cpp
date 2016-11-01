/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here

        int len = 0;
        ListNode* cur = head;
        while(cur){
            len++;
            cur = cur->next;
        }

        return middleNode(head, len);
    }
    
    TreeNode* middleNode(ListNode *&pos, int len){
        if(len <= 0) return NULL;
        
        TreeNode * left = middleNode(pos, len/2);
        TreeNode* root = new TreeNode(pos->val);
        pos = pos->next;
        root->left = left;
        
        root->right = middleNode(pos, len-len/2-1);
        
        return root;
    }
};


